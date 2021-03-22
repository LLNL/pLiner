#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/Stmt.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Casting.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "llvm/Support/raw_ostream.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "FPDebugger.h"
#include "analysis/funcAnalysis.h"
#include "analysis/funcPrint.h"
#include "transform/funcTrans.h"
#include "core/_funcRecord.h"
#include "json.hpp"

using namespace clang;
using namespace clang::tooling;
using namespace std;
using namespace llvm;
using json=nlohmann::json;

std::string infofname = "funcinfo.txt";
std::string prof_prefix = "pLiner";

std::string outfilename;

bool transWholeFunc = false;

std::vector<std::string> funclist;
std::set<std::string> pfuncs;
std::map<std::string, std::vector<std::pair<unsigned, unsigned>>> pfregions; 

std::string myreal;

static cl::OptionCategory FPDebuggerCat("pLiner Options");

static cl::opt<bool> printOnly("po",cl::desc("flag that specifies whether to print the functions only, false in default"),
                     cl::init(false), cl::cat(FPDebuggerCat));
static cl::opt<bool> analysisOnly("ao",cl::desc("flag that specifies whether to perform the analysis only, false in default"),
                     cl::init(false), cl::cat(FPDebuggerCat));
static cl::opt<bool> wholetransformation("whole",cl::desc("flag that specifies whether to perform the transformation for the whole function, false in default"),
                     cl::init(false), cl::cat(FPDebuggerCat));

static cl::opt<string> inRegions("r",cl::desc("a json file that contains the region list for transformation"),
                     cl::init("pLiner-input.json"), cl::cat(FPDebuggerCat));
static cl::opt<string> outFileName("o",cl::desc("name of the transformed file"),
                     cl::init("output.txt"), cl::cat(FPDebuggerCat));
static cl::opt<string> myReal("h",cl::desc("high precision"),
                     cl::init("long double"), cl::cat(FPDebuggerCat));

int main(int argc, const char **argv) {

  // Parse the command-line args passed to the code
  CommonOptionsParser op(argc, argv, FPDebuggerCat, nullptr);
  
  // Create a new Clang Tool instance 
  ClangTool Tool(op.getCompilations(), op.getSourcePathList());

  // Only to print the function names 
  int result;
  if (printOnly) {
    result = Tool.run(newFrontendActionFactory<funcPrintAction>().get());

    json j;
    json j_vec(funclist); 
    j["pLiner-funcs"] = j_vec;
    std::ofstream o("func-list.json");
    o << std::setw(4) << j << std::endl;

    return result;
  }

  // Read analysis and transformation arguments
  transWholeFunc = wholetransformation;
  myreal = myReal;
  outfilename = outFileName;

  std::ifstream file;
  file.open(inRegions);
  json j = json::parse(file);
  file.close();

  json infuncs = j["pLiner-funcs"];
  for(unsigned i=0; i<infuncs.size(); i++){
    pfuncs.insert(std::string(infuncs[i]));
  }

  if (!analysisOnly && !wholetransformation){
    json infregions = j["pLiner-fregions"]; 
    
    for(std::set<std::string>::iterator it=pfuncs.begin(); it!=pfuncs.end(); it++){
      std::string pfunc = *it;
      json regions = infregions[pfunc];
      pfregions[pfunc] = std::vector<std::pair<unsigned, unsigned>>(); 
      //std::cout << pfunc << ":" << std::endl;
      for(unsigned k=0; k<regions.size(); k++){
        pfregions[pfunc].push_back(std::make_pair(regions[k][0], regions[k][1]));
        //std::cout << "  " << regions[k][0] << "->" << regions[k][1] << std::endl;
      }   
    }
  } 

  // Run the Clang Tool, creating a new FrontendAction
  if (analysisOnly) 
    result = Tool.run(newFrontendActionFactory<funcAnalysisAction>().get());
  else
    result = Tool.run(newFrontendActionFactory<funcTransAction>().get());
  
  return result;
}
