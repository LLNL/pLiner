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

#include "funcPrint.h"
#include "../FPDebugger.h"

using namespace clang::tooling;

int numPFunctions = 0;
Rewriter pRewriter;

class funcPrintVisitor : public RecursiveASTVisitor<funcPrintVisitor> {
public:
  explicit funcPrintVisitor(ASTContext *Context) : Context(Context) {}

  virtual bool VisitFunctionDecl(FunctionDecl *func) {
    if (!func->doesThisDeclarationHaveABody())
	return true;
    SourceManager &SM = pRewriter.getSourceMgr();
    string fileInProcess = SM.getFileEntryForID(SM.getMainFileID())->getName();
    string funcFile = Context->getSourceManager().getFilename(func->getLocation()).str();
    if (funcFile != fileInProcess)
        return true;
 
    string funcName = func->getNameInfo().getName().getAsString();

    funclist.push_back(funcName);

    numPFunctions++;
     
    outs() << "** function " << numPFunctions << " : " << funcName << ", in file " << funcFile << "\n";
    return true;     
  }   
 
private:
  ASTContext *Context;
};

class funcPrintConsumer : public clang::ASTConsumer {
public:
  explicit funcPrintConsumer(ASTContext *Context) : Visitor(Context) {}

  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }
private:
  funcPrintVisitor Visitor;
};

std::unique_ptr<clang::ASTConsumer> funcPrintAction::CreateASTConsumer(
  clang::CompilerInstance &CI, StringRef InFile) {
  
  pRewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());
  
  outs() << "** Creating funcPrint AST consumer for: " << InFile << "\n";
  return std::unique_ptr<clang::ASTConsumer>(
      new funcPrintConsumer(&CI.getASTContext()));
}

void funcPrintAction::EndSourceFileAction(){
  SourceManager &SM = pRewriter.getSourceMgr();
  outs() << "** End funcPrint Action for: "
               << SM.getFileEntryForID(SM.getMainFileID())->getName() << "\n";
}
