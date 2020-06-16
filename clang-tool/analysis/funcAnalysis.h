#include "clang/Tooling/Tooling.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/CommonOptionsParser.h"

using namespace llvm;
using namespace std;
using namespace clang;

class funcAnalysisAction : public clang::ASTFrontendAction {
public:
  virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
    clang::CompilerInstance &CI, StringRef InFile);
  void EndSourceFileAction();
};
