#include "clang/AST/Decl.h"
#include "clang/AST/ASTContext.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include <vector>
#include <tuple>
#include <map>

#include "_lineRecord.h"

using namespace clang;
using namespace std;

class _funcRecord{
  FunctionDecl *funcDel;
  string funcName;
  string fileName;
  vector<const ParmVarDecl*> fpparalist;
  vector<const ParmVarDecl*> fpPointerparalist;
  vector<const VarDecl*> fpvarlist;
  vector<const VarDecl*> fpPointervarlist;
  vector<tuple<unsigned, unsigned>> forloops;
  map<unsigned, tuple<unsigned, unsigned>> bblist;
  map<unsigned, _lineRecord*> lineRs;

  map<const VarDecl*, string> newFPDels;
  string typeTransTo;
  unsigned int tmpNo;
 
  stringstream regEntry, regExit;
  bool insertEntry, insertExit;
  unsigned regLstart, regLend;
  const Stmt* cursor;

  ASTContext* context;  
public:
  //_funcRecord(FunctionDecl *func) : funcDel(func), funcName(func->getNameInfo().getName().getAsString()) {};
  _funcRecord(FunctionDecl *func, ASTContext* context);
  void processFPParameters();
  void processBBs();
  void processLoops();
  void processLines();
  void printFuncRecord(string filename);

  void transRegion(unsigned lstart, unsigned lend, Rewriter& TheRewriter, string myReal);
  void transWhole(Rewriter& TheRewriter, string myReal);

private:
  void processForLoops(const Stmt* st);
  void processStmts(const Stmt* st);
  void processReturnStmt(const ReturnStmt* rst, _lineRecord * lRp);
  void processWhileStmt(const WhileStmt* wst, _lineRecord * lRp);
  void processForStmt(const ForStmt* forst, _lineRecord * lRp);
  void processIfStmt(const IfStmt* ifst, _lineRecord * lRp);
  void processSwitchStmt(const SwitchStmt* swst, _lineRecord * lRp);
  void processDeclStmt(const DeclStmt* delst, _lineRecord * lRp);
  void processBinaryOpStmt(const BinaryOperator* bst, _lineRecord * lRp);
  void processCompoundAOpStmt(const CompoundAssignOperator* comast, _lineRecord * lRp);
  vector<const clang::Expr*>& processCallExprStmt(const CallExpr* callep, _lineRecord * lRp);
  vector<const DeclRefExpr*>& obtainReads(const clang::Expr* epr, unsigned line, _lineRecord *lRp);

  void handleFPParameters(Rewriter& TheRewriter);
  void handleReads(Rewriter& TheRewriter, const clang::Expr* epr);

  void handleWholeSyncs(Rewriter& TheRewriter, const Stmt* statement);
  void transWholeStmts(Rewriter& TheRewriter, const Stmt* st);
  void transWholeReturnStmt(Rewriter& TheRewriter, const ReturnStmt* rst);
  void transWholeWhileStmt(Rewriter& TheRewriter, const WhileStmt* wst);
  void transWholeForStmt(Rewriter& TheRewriter, const ForStmt* forst);
  void transWholeIfStmt(Rewriter& TheRewriter, const IfStmt* ifst);
  void transWholeSwitchStmt(Rewriter& TheRewriter, const SwitchStmt* swst);
  void transWholeDeclStmt(Rewriter& TheRewriter, const DeclStmt* delst);
  void transWholeBinaryOpStmt(Rewriter& TheRewriter, const BinaryOperator* bst);
  void transWholeCompoundAOpStmt(Rewriter& TheRewriter, const CompoundAssignOperator* comast);
  void transWholeCallExprStmt(Rewriter& TheRewriter, const CallExpr* callep);
  int handleFuncParamReads(Rewriter& TheRewriter, const clang::Expr* epr);
  string enhanceFormatSpecifierPrecision(string printf_format_specifier, vector<int> paramTransformed);
  
  void handleRegionSyncs(Rewriter& TheRewriter, const Stmt* statement);
  void handleRegionEE(unsigned lstart, unsigned lend, Rewriter& TheRewriter);

  void transRegionStmts(Rewriter& TheRewriter, const Stmt* st);
  void transRegionDeclStmt(Rewriter& TheRewriter, const DeclStmt* delst);
  void transRegionWhileStmt(Rewriter& TheRewriter, const WhileStmt* wst);
  void transRegionForStmt(Rewriter& TheRewriter, const ForStmt* forst);
  void transRegionIfStmt(Rewriter& TheRewriter, const IfStmt* ifst);
  void transRegionSwitchStmt(Rewriter& TheRewriter, const SwitchStmt* swst);
  void transRegionCallExprStmt(Rewriter& TheRewriter, const CallExpr* callep);

};
