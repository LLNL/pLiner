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

#include "funcTrans.h"
#include "../FPDebugger.h"
#include "../core/_funcRecord.h"

using namespace clang::tooling;

int numTFunctions = 0;
Rewriter TRewriter;

class funcTransVisitor : public RecursiveASTVisitor<funcTransVisitor> {
public:
  explicit funcTransVisitor(ASTContext *Context) : Context(Context) {}

  virtual bool VisitFunctionDecl(FunctionDecl *func) {
    if (!func->doesThisDeclarationHaveABody())
	return true;
    string funcName = func->getNameInfo().getName().getAsString();

    if (pfuncs.find(funcName)!=pfuncs.end()) {
      numTFunctions++;
      outs() << "\n** function " << numTFunctions << " : " << funcName << "\n";

      _funcRecord frecord(func, Context);

      frecord.processFPParameters();
      frecord.processLines();

      if (transWholeFunc)
        frecord.transWhole(TRewriter, myreal);
      else
        for (vector<pair<unsigned, unsigned>>::iterator regit=pfregions[funcName].begin(); regit!=pfregions[funcName].end(); regit++){
          unsigned rstart = regit->first;
          unsigned rend = regit->second;
          frecord.transRegion(rstart, rend, TRewriter, myreal);
        }
    }       
    return true;     
  }   
 
private:
  ASTContext *Context;
};

class funcTransConsumer : public clang::ASTConsumer {
public:
  explicit funcTransConsumer(ASTContext *Context) : Visitor(Context) {}

  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }
private:
  funcTransVisitor Visitor;
};

std::unique_ptr<clang::ASTConsumer> funcTransAction::CreateASTConsumer(
  clang::CompilerInstance &CI, StringRef InFile) {
  outs() << "** Creating funcTrans AST consumer for: " << InFile << "\n";
  TRewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());
  return std::unique_ptr<clang::ASTConsumer>(
      new funcTransConsumer(&CI.getASTContext()));
}

void funcTransAction::EndSourceFileAction(){
  SourceManager &SM = TRewriter.getSourceMgr();
  outs() << "** End funcTrans Action for: "
               << SM.getFileEntryForID(SM.getMainFileID())->getName() << "\n";

  // Now emit the rewritten buffer.
  std::error_code error_code;
  llvm::raw_fd_ostream outFile(outfilename, error_code, llvm::sys::fs::F_None);
  TRewriter.getEditBuffer(SM.getMainFileID()).write(outFile); 
  outFile.close();
}
