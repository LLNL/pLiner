#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/Stmt.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Rewrite/Core/Rewriter.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "funcAnalysis.h"
#include "../FPDebugger.h"
#include "../core/_funcRecord.h"

using namespace clang::tooling;

int numAFunctions = 0;
Rewriter AnRewriter;

class funcAnalysisVisitor : public RecursiveASTVisitor<funcAnalysisVisitor> {
public:
  explicit funcAnalysisVisitor(ASTContext *Context) : Context(Context) {}

  virtual bool VisitFunctionDecl(FunctionDecl *func) {
    if (!func->doesThisDeclarationHaveABody())
	return true;
    string funcName = func->getNameInfo().getName().getAsString();

    if (pfuncs.find(funcName)!=pfuncs.end()) {
      numAFunctions++;
      outs() << "\n** function " << numAFunctions << " : " << funcName << "\n";

      _funcRecord frecord(func, Context);

      frecord.processFPParameters();
      frecord.processBBs();
      frecord.processLoops();
      frecord.processLines();
 
      //outs() << "** function " << numAFunctions << " : " << funcName << "\n";
      frecord.printFuncRecord(prof_prefix+'-'+funcName);
    }       
    return true;     
  }   
 
private:
  ASTContext *Context;
};

class funcAnalysisConsumer : public clang::ASTConsumer {
public:
  explicit funcAnalysisConsumer(ASTContext *Context) : Visitor(Context) {}

  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }
private:
  funcAnalysisVisitor Visitor;
};

std::unique_ptr<clang::ASTConsumer> funcAnalysisAction::CreateASTConsumer(
  clang::CompilerInstance &CI, StringRef InFile) {
  
  AnRewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());
  
  outs() << "** Creating funcAnalysis AST consumer for: " << InFile << "\n";
  return std::unique_ptr<clang::ASTConsumer>(
      new funcAnalysisConsumer(&CI.getASTContext()));
}

void funcAnalysisAction::EndSourceFileAction(){
  SourceManager &SM = AnRewriter.getSourceMgr();
  outs() << "** End funcAnalysis Action for: "
               << SM.getFileEntryForID(SM.getMainFileID())->getName() << "\n";
}
