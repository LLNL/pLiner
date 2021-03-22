#include "clang/Basic/LangOptions.h"
#include "clang/Analysis/CFG.h"
#include "clang/Basic/SourceManager.h" 
#include "clang/AST/Expr.h"
#include "llvm/Support/raw_ostream.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

#include "_fp.h"
#include "_funcRecord.h"
#include "../FPDebugger.h"

using namespace llvm;

_funcRecord::_funcRecord(FunctionDecl *func, ASTContext* Context){
  context = Context;
  funcDel = func;
  funcName = func->getNameInfo().getName().getAsString();
  fileName = context->getSourceManager().getFilename(func->getLocation()).str();
  cursor = NULL;
  tmpNo = 0; 
}


//==================
//analysis
//==================

void _funcRecord::processFPParameters(){
  if (funcDel->param_begin())
    for (const auto * parameter : funcDel->parameters()){
      const clang::Type* ty = parameter->getOriginalType().getTypePtr();
      if (isDouble(ty, context))
        fpparalist.push_back(parameter);
      if (isDoublePointer(ty, context) || isDoubleArray(ty, context))
        fpPointerparalist.push_back(parameter);
    }
}

void _funcRecord::processBBs(){
  // create CFG
  std::unique_ptr<CFG> sourceCFG = CFG::buildCFG(funcDel, funcDel->getBody(), context, CFG::BuildOptions());
  //sourceCFG->print(llvm::errs(), LangOptions(), true);
  
  // traverse through CFG blocks
  CFG::const_iterator CFGBI;
  for (CFGBI = sourceCFG->begin(); CFGBI != sourceCFG->end(); CFGBI++){
    CFGBlock* block = *CFGBI;
    if (block->empty())
      continue;
		
    const Stmt * front = block->front().getAs<CFGStmt>()->getStmt();
    const Stmt * back = block->back().getAs<CFGStmt>()->getStmt();
    SourceLocation fSL = front->getSourceRange().getBegin();
    SourceLocation bSL = back->getSourceRange().getEnd();
    unsigned frontLine = context->getFullLoc(fSL).getSpellingLineNumber();
    unsigned backLine = context->getFullLoc(bSL).getSpellingLineNumber();
    
    if(isa<BinaryOperator>(back)){
      const Stmt * extra = back;
      SourceLocation efSL = extra->getSourceRange().getBegin();
      SourceLocation ebSL = extra->getSourceRange().getEnd();
      unsigned efrontLine = context->getFullLoc(efSL).getSpellingLineNumber();
      unsigned ebackLine = context->getFullLoc(ebSL).getSpellingLineNumber();
      bblist[block->getBlockID()+10000] = std::make_tuple(efrontLine, ebackLine);

      if (block->end() - block->begin() > 1){
        back = (*(block->end()-2)).getAs<CFGStmt>()->getStmt();
        bSL = back->getSourceRange().getEnd();
        backLine = context->getFullLoc(bSL).getSpellingLineNumber();

        bblist[block->getBlockID()] = std::make_tuple(frontLine, backLine);
      }
    } else {
      bblist[block->getBlockID()] = std::make_tuple(frontLine, backLine);
    }
    //llvm::errs() << "block back stmt on line " << backLine << ":\n";
    //back->dump();
  }  
}

void _funcRecord::processForLoops(const Stmt* st){
  // for loops
  if(const ForStmt* forst = dyn_cast<ForStmt>(st)){
    SourceLocation BSL = st->getSourceRange().getBegin();
    SourceLocation ESL = st->getSourceRange().getEnd();
  
    unsigned start = context->getFullLoc(BSL).getSpellingLineNumber();
    unsigned end = context->getFullLoc(ESL).getSpellingLineNumber();

    forloops.push_back( std::make_tuple(start, end));
    if(const Stmt* forBodyStmt = dyn_cast<Stmt>(forst->getBody())){
      processForLoops(forBodyStmt);
    }
    else{
    const CompoundStmt *forBody = dyn_cast<CompoundStmt>(forst->getBody());
    CompoundStmt::const_body_iterator stmtI;
    for (stmtI =forBody->body_begin(); stmtI != forBody->body_end(); stmtI++){
      const Stmt * st = *stmtI;
      processForLoops(st);
    }
    }
  }

  // if statement
  if(const IfStmt* ifst = dyn_cast<IfStmt>(st)){ 
    if(const Stmt* thenst = dyn_cast<Stmt>(ifst->getThen()))
      processForLoops(thenst);
    if(const CompoundStmt *thenBody = dyn_cast<CompoundStmt>(ifst->getThen())){
      CompoundStmt::const_body_iterator stmtI;
      for (stmtI =thenBody->body_begin(); stmtI != thenBody->body_end(); stmtI++){
        const Stmt * st = *stmtI;
        //st->dump();
        processForLoops(st);
      }
    }

    if (ifst->hasElseStorage()){
      if(const Stmt* elsest = dyn_cast<Stmt>(ifst->getElse()))
        processForLoops(elsest);
      if(const CompoundStmt *elseBody = dyn_cast<CompoundStmt>(ifst->getElse())){
        CompoundStmt::const_body_iterator stmtI;
        for (stmtI =elseBody->body_begin(); stmtI != elseBody->body_end(); stmtI++){
          const Stmt * st = *stmtI;
          //st->dump();
          processForLoops(st);
        }
      }
    } // end of else branch

  } // end of if statement

}

void _funcRecord::processLoops(){
  const CompoundStmt *fBody = dyn_cast<CompoundStmt>(funcDel->getBody());
  CompoundStmt::const_body_iterator stmtI;
  for (stmtI =fBody->body_begin(); stmtI != fBody->body_end(); stmtI++){
    const Stmt * st = *stmtI;
    processForLoops(st);
  }
}
 
void _funcRecord::processStmts(const Stmt* statement){
  SourceLocation SL = statement->getSourceRange().getBegin();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();
  map<unsigned, _lineRecord*>::iterator lineI = lineRs.find(line);
  _lineRecord * lRp; 
  if (lineI == lineRs.end()){
    lRp = new _lineRecord(line); lineRs[line] = lRp;
  } else {
    lRp = lineI->second;	
  }

  string type = statement->getStmtClassName();
  Debug(llvm::errs() << " < to handle Statement: " << type << " , line " << line << "\n"); 
  if (type == "ReturnStmt") {
    auto rs = dyn_cast<const ReturnStmt>(statement);
    processReturnStmt(rs, lRp);
  } else if (type == "WhileStmt") {
    auto ws = dyn_cast<WhileStmt>(statement);
    processWhileStmt(ws, lRp);
  } else if (type == "ForStmt") {
    auto fs = dyn_cast<const ForStmt>(statement);
    processForStmt(fs, lRp);
  } else if (type == "IfStmt") {
    auto is = dyn_cast<const IfStmt>(statement);
    processIfStmt(is, lRp);
  } else if (type == "SwitchStmt") {
    auto ss = dyn_cast<const SwitchStmt>(statement);
    processSwitchStmt(ss, lRp);
  } else if (type == "DeclStmt"){
    auto ds = dyn_cast<const DeclStmt>(statement);
    processDeclStmt(ds, lRp);
  } else if (type == "BinaryOperator") {
    auto bs = dyn_cast<BinaryOperator>(statement);
    processBinaryOpStmt(bs, lRp);
  } else if (type == "CompoundAssignOperator") {
    auto comas = dyn_cast<CompoundAssignOperator>(statement);
    processCompoundAOpStmt(comas, lRp);
  } else if (type == "CompoundStmt") {
    auto cs = dyn_cast<const CompoundStmt>(statement);
    for (auto child : cs->children())
      processStmts(child);
  } else if (type == "CallExpr") {
    auto callep = dyn_cast<CallExpr>(statement);
    processCallExprStmt(callep, lRp);
  } else {
    llvm::errs() << "Unhandled Statement: " << type << " , line " << line << "\n"; 
  }
  Debug(llvm::errs() << " > handled Statement: " << type << " , line " << line << "\n"); 
 
  //SourceLocation exitSL = statement->getEndLoc();
  //unsigned exitLine = context->getFullLoc(exitSL).getSpellingLineNumber();
  //unsigned off=0;
  //string ch = exitSL.getLocWithOffset(off).printToString(context->getSourceManager()); 
  //outs() << type << "on line " << exitLine << ": " << ch << "\n;";
}

//vector<const DeclRefExpr*>& _funcRecord::obtainReads(const clang::Expr* epr, unsigned line, _lineRecord* lRp){
//  vector<const DeclRefExpr*>* reads = new std::vector<const DeclRefExpr*>();
  //string ch = exitSL.getLocWithOffset(off).printToString(context->getSourceManager()); 
  //outs() << type << "on line " << exitLine << ": " << ch << "\n;";
//}

vector<const DeclRefExpr*>& _funcRecord::obtainReads(const clang::Expr* epr, unsigned line, _lineRecord* lRp){
  vector<const DeclRefExpr*>* reads = new std::vector<const DeclRefExpr*>();
  if (epr==nullptr)
    return *reads;

  vector<const clang::Expr*> wlist;
  wlist.push_back(epr);
  while (!wlist.empty()){
    epr = wlist.back(); wlist.pop_back();
    if (auto arr = dyn_cast<ArraySubscriptExpr>(epr)){
      epr = arr->getBase()->IgnoreParenImpCasts();
    }
    if (auto readV = dyn_cast<DeclRefExpr>(epr)){
      const clang::Type* ty= readV->getDecl()->getType().getTypePtr();
      if (isDoubleBase(ty, context))
        reads->push_back(readV); 
    }else if (auto bop = dyn_cast<BinaryOperator>(epr)){
      wlist.push_back(bop->getLHS()->IgnoreParenImpCasts());
      wlist.push_back(bop->getRHS()->IgnoreParenImpCasts());
    }else if (auto cop = dyn_cast<ConditionalOperator>(epr)){
      wlist.push_back(cop->getCond()->IgnoreParenImpCasts());
      wlist.push_back(cop->getTrueExpr()->IgnoreParenImpCasts());
      wlist.push_back(cop->getFalseExpr()->IgnoreParenImpCasts());
    }else if (auto uop = dyn_cast<UnaryOperator>(epr)){
      StringRef opcode=uop->getOpcodeStr(uop->getOpcode());
      clang::Expr* upr = uop->getSubExpr()->IgnoreParenImpCasts();
      if (opcode != "&"){
        wlist.push_back(upr);
      }
      //if (auto uarr = dyn_cast<ArraySubscriptExpr>(upr)){
      //  upr = uarr->getBase()->IgnoreParenImpCasts();
      //}
      //if (auto ureadV = dyn_cast<DeclRefExpr>(upr)){
      //  const clang::Type* uty= ureadV->getDecl()->getType().getTypePtr();
      //  if (isDoubleBase(uty, context)){
      //    lRp->addSync(ureadV);
      //  }
      //} 
    }else if (auto callop = dyn_cast<CallExpr>(epr)){
      vector<const clang::Expr*> calleps = processCallExprStmt(callop, lRp);
      vector<const clang::Expr*>::iterator it=wlist.end();
      wlist.insert(it, calleps.begin(), calleps.end());
      //if (auto callee = dyn_cast<const clang::NamedDecl>(callop->getCalleeDecl())){
      //llvm:errs() << "unaryopcode : "<< opcode << " on line " << line << "\n";
      //  //llvm::errs() << "call expr (line " << line << " ): " << callee->getNameAsString() << "\n"; // non
      //  if(lRp != nullptr)
      //    lRp->addCall(callop);
      //}
      //for (const auto * epr : callop->arguments())
      //  if (!isa<CXXDefaultArgExpr>(epr))
      //    wlist.push_back(epr->IgnoreParenImpCasts());
    } else if ( string(epr->getStmtClassName()) == "IntegerLiteral" || string(epr->getStmtClassName()) == "FloatingLiteral"){
      // llvm::errs() << "an  interger/floating literal (line " << lRp->lineNum << " )\n"; // non
    } else {
      llvm::errs() << "failed to obtain the variable an assignment (line " << line << ") reads.\n"; 
    }  
  }

  return *reads;
 
}

void _funcRecord::processReturnStmt(const ReturnStmt* rst, _lineRecord * lRp){
  //llvm::errs() << "Incomplete function : processReturnStmt \n"; 
  const clang::Expr* epr = rst->getRetValue()->IgnoreParenImpCasts();

  vector<const DeclRefExpr*>& reads = obtainReads(epr, lRp->lineNum, lRp);
  for (const auto* readV : reads){
    if (isDoubleBase(readV->getDecl()->getType().getTypePtr(), context))
      lRp->addRead(readV);
  }
}

void _funcRecord::processBinaryOpStmt(const BinaryOperator* bst, _lineRecord * lRp){
  //llvm::errs() << "Incomplete function : processBinaryOpStmt \n";
  if(!bst->isAssignmentOp())
    return;
  
  const clang::Type* ty = bst->getType().getTypePtr();
  if (isDouble(ty, context)){ // double 
    const clang::Expr* lhs = bst->getLHS()->IgnoreParenImpCasts(); // obtain the variable it writes
    if (auto arr = dyn_cast<ArraySubscriptExpr>(lhs)){
      lhs = arr->getBase()->IgnoreParenImpCasts();
    }
    if (auto writeV = dyn_cast<DeclRefExpr>(lhs)){
      const clang::Type* ty= writeV->getDecl()->getType().getTypePtr();
      if (isDoubleBase(ty, context)) 
        lRp->addWrite(writeV);
    } else {
      llvm::errs() << "failed to obtain the variable an assignment (line " << lRp->lineNum << ") writes to.\n"; 
    }
   
    const clang::Expr* rhs = bst->getRHS()->IgnoreParenImpCasts();
    vector<const DeclRefExpr*>& reads = obtainReads(rhs, lRp->lineNum, lRp);
    for (const auto* readV : reads){
      if (isDoubleBase(readV->getDecl()->getType().getTypePtr(), context))
        lRp->addRead(readV);
    }
  }
}


vector<const clang::Expr*>& _funcRecord::processCallExprStmt(const CallExpr* callep, _lineRecord * lRp){
  lRp->addCall(callep);

  SourceLocation SL = callep->getExprLoc();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();

  if (auto callee = dyn_cast<const clang::NamedDecl>(callep->getCalleeDecl())){
    const string cname = callee->getNameAsString(); 
    if (mathcalls.find(cname) == mathcalls.end())
      Debug(llvm::errs() << "call expr (line " << line << " ): " << callee->getNameAsString() << "\n"); // non
  }

  vector<const clang::Expr*>* retlist = new std::vector<const clang::Expr*>();

  for (const auto * epr : callep->arguments()){
    if (isa<CXXDefaultArgExpr>(epr))
      continue;
    //obtainReads(epr, lRp->lineNum, lRp);
    if (auto uop = dyn_cast<UnaryOperator>(epr)){
      StringRef opcode=uop->getOpcodeStr(uop->getOpcode());
      //llvm:errs() << "unaryopcode : "<< opcode << " on line " << line << "\n";
      clang::Expr* upr = uop->getSubExpr()->IgnoreParenImpCasts();
      if (opcode != "&"){
        retlist->push_back(upr);
        continue;
      }
      if (auto uarr = dyn_cast<ArraySubscriptExpr>(upr)){
        upr = uarr->getBase()->IgnoreParenImpCasts();
      }
      if (auto ureadV = dyn_cast<DeclRefExpr>(upr)){
        const clang::Type* uty= ureadV->getDecl()->getType().getTypePtr();
        if (isDoubleBase(uty, context)){
          lRp->addSync(ureadV);
        }
      } 
    } else {
      retlist->push_back(epr->IgnoreParenImpCasts());
   }  
  }

  return *retlist;
}

void _funcRecord::processCompoundAOpStmt(const CompoundAssignOperator* comast, _lineRecord * lRp){
  //llvm::errs() << "Incomplete function : processCompoundAOpStmt \n"; 
  const clang::Type* ty = comast->getType().getTypePtr();
  if (isDouble(ty, context)){ // double 
    const clang::Expr* lhs = comast->getLHS()->IgnoreParenImpCasts(); // obtain the variable it writes
    if (auto arr = dyn_cast<ArraySubscriptExpr>(lhs)){
      lhs = arr->getBase()->IgnoreParenImpCasts();
    }
    if (auto writeV = dyn_cast<DeclRefExpr>(lhs)){
      const clang::Type* ty= writeV->getDecl()->getType().getTypePtr();
      if (isDoubleBase(ty, context)){ 
        lRp->addWrite(writeV);
        lRp->addRead(writeV);
      }
    } else {
      llvm::errs() << "failed to obtain the variable an assignment (line " << lRp->lineNum << ") writes to.\n"; 
    }
   
    const clang::Expr* rhs = comast->getRHS()->IgnoreParenImpCasts();
    vector<const DeclRefExpr*>& reads = obtainReads(rhs, lRp->lineNum, lRp);
    for (const auto* readV : reads){
      if (isDoubleBase(readV->getDecl()->getType().getTypePtr(), context))
        lRp->addRead(readV);
    }
  }
}

void _funcRecord::processWhileStmt(const WhileStmt* wst, _lineRecord * lRp){
  //llvm::errs() << "Incomplete function : processWhileStmt \n";
  const Expr* cond = wst->getCond()->IgnoreParenImpCasts();
  vector<const DeclRefExpr*>& reads = obtainReads(cond, lRp->lineNum, lRp);
  for (const auto* readV : reads){
    if (isDoubleBase(readV->getDecl()->getType().getTypePtr(), context))
      lRp->addRead(readV);
  }
 
  if(const Stmt* dost = dyn_cast<Stmt>(wst->getBody()))
    processStmts(dost);
  else
    if(const CompoundStmt *doBody = dyn_cast<CompoundStmt>(wst->getBody())){
      CompoundStmt::const_body_iterator stmtI;
      for (stmtI =doBody->body_begin(); stmtI != doBody->body_end(); stmtI++){
        const Stmt * st = *stmtI;
        //st->dump();
        processStmts(st);
      }
    }
}

void _funcRecord::processForStmt(const ForStmt* forst, _lineRecord * lRp){
  // for loops
  const CompoundStmt *forBody = dyn_cast<CompoundStmt>(forst->getBody());
  if(const Stmt* forBodyStmt = dyn_cast<Stmt>(forst->getBody())){
    processStmts(forBodyStmt);
  } 
  else{
    CompoundStmt::const_body_iterator stmtI;
    for (stmtI =forBody->body_begin(); stmtI != forBody->body_end(); stmtI++){
      const Stmt * st = *stmtI;
      //st->dump();
      processStmts(st);
    }
  }
}

void _funcRecord::processIfStmt(const IfStmt* ifst, _lineRecord * lRp){
  // if statement
  const Expr* cond = ifst->getCond()->IgnoreParenImpCasts();
  vector<const DeclRefExpr*>& reads = obtainReads(cond, lRp->lineNum, lRp);
  for (const auto* readV : reads){
    if (isDoubleBase(readV->getDecl()->getType().getTypePtr(), context))
      lRp->addRead(readV);
  }
   
  if(const Stmt* thenst = dyn_cast<Stmt>(ifst->getThen()))
    processStmts(thenst);
  else
    if(const CompoundStmt *thenBody = dyn_cast<CompoundStmt>(ifst->getThen())){
      CompoundStmt::const_body_iterator stmtI;
      for (stmtI =thenBody->body_begin(); stmtI != thenBody->body_end(); stmtI++){
        const Stmt * st = *stmtI;
        //st->dump();
        processStmts(st);
      }
    }
  
  if (ifst->hasElseStorage()){
    if(const Stmt* elsest = dyn_cast<Stmt>(ifst->getElse()))
      processStmts(elsest);
    else
      if(const CompoundStmt *elseBody = dyn_cast<CompoundStmt>(ifst->getElse())){
        CompoundStmt::const_body_iterator stmtI;
        for (stmtI =elseBody->body_begin(); stmtI != elseBody->body_end(); stmtI++){
          const Stmt * st = *stmtI;
          processStmts(st);
        }
      }
  } 
}


void _funcRecord::processSwitchStmt(const SwitchStmt* swst, _lineRecord * lRp){
  llvm::errs() << "Incomplete function : processSwitchStmt \n"; 
}

void _funcRecord::processDeclStmt(const DeclStmt* delst, _lineRecord * lRp){
  //var declaration statements
  for(const auto * vdI = delst->decl_begin(); vdI != delst->decl_end(); vdI++){
    const VarDecl *vd = dyn_cast<VarDecl>(*vdI);
    const clang::Type* ty = vd->getType().getTypePtr();
    if (isDouble(ty, context)){ // double local variables
      fpvarlist.push_back(vd);
      lRp->addVDel(vd);
    }
            
    if (isDoubleArray(ty, context) || isDoublePointer(ty, context)){// double array local variables
      fpPointervarlist.push_back(vd);
      lRp->addVDel(vd);
    }
    
    if (vd->hasInit()){
      const clang::Expr* epr = vd->getInit()->IgnoreParenImpCasts();
      vector<const clang::DeclRefExpr*>& reads = obtainReads(epr, lRp->lineNum, lRp);
      for (const auto * readV : reads){
        if (isDoubleBase(readV->getDecl()->getType().getTypePtr(), context))
          lRp->addRead(readV);
      }
    }
  }
}

void _funcRecord::processLines(){
  const CompoundStmt *fBody = dyn_cast<CompoundStmt>(funcDel->getBody());
  CompoundStmt::const_body_iterator stmtI;
  for (stmtI =fBody->body_begin(); stmtI != fBody->body_end(); stmtI++){
    const Stmt * st = *stmtI;
    processStmts(st);
  } 
}


//==================
//transformation
//==================

void _funcRecord::handleFPParameters(Rewriter& TheRewriter){
  stringstream fparaH;

  for (const auto * parameter : fpparalist){
    string pname = parameter->getNameAsString();
    string pqualifiers = parameter->getOriginalType().getQualifiers().getAsString();
    fparaH << pqualifiers+" "+typeTransTo << " " << pname << "_H = "<< pname << ";\n"; 
    newFPDels[parameter] = pname+"_H"; 
  }
 
  const CompoundStmt *fBody = dyn_cast<CompoundStmt>(funcDel->getBody());
  CompoundStmt::const_body_iterator stmtI = fBody->body_begin();
  SourceLocation SL = (*stmtI)->getSourceRange().getBegin();

  TheRewriter.InsertText(SL.getLocWithOffset(0), fparaH.str()+regEntry.str(), false, true);
}

void _funcRecord::handleReads(Rewriter& TheRewriter, const clang::Expr* epr){
  if (epr==nullptr)
    return;

  SourceLocation SL = epr->getExprLoc();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();

  vector<const clang::VarDecl*> synclist;

  vector<const clang::Expr*> wlist;
  wlist.push_back(epr);

  while (!wlist.empty()){
    epr = wlist.back(); wlist.pop_back();
    if (auto arr = dyn_cast<ArraySubscriptExpr>(epr)){
      epr = arr->getBase()->IgnoreParenImpCasts();
    }
    if (auto readV = dyn_cast<DeclRefExpr>(epr)){
      const clang::Type* ty= readV->getDecl()->getType().getTypePtr();
      if (isDoubleBase(ty, context)){
        //reads->push_back(readV);
        const VarDecl* vdel = dyn_cast<VarDecl>(readV->getDecl()); 
        string vname = readV->getNameInfo().getAsString();
        map<const VarDecl*, string>::iterator it = newFPDels.find(vdel);
        if (it == newFPDels.end()){
          TheRewriter.InsertText(readV->getExprLoc(), "("+typeTransTo+")", false, false);
        }else{
          string newvname = newFPDels[vdel];
          TheRewriter.ReplaceText(readV->getExprLoc(), vname.length(), newvname);
          //llvm::errs() << "handled " << vname << " on line " << line << "\n"; 
        }
      }
    }else if (auto bop = dyn_cast<BinaryOperator>(epr)){
      wlist.push_back(bop->getLHS()->IgnoreParenImpCasts());
      wlist.push_back(bop->getRHS()->IgnoreParenImpCasts());
    }else if (auto cop = dyn_cast<ConditionalOperator>(epr)){
      wlist.push_back(cop->getCond()->IgnoreParenImpCasts());
      wlist.push_back(cop->getTrueExpr()->IgnoreParenImpCasts());
      wlist.push_back(cop->getFalseExpr()->IgnoreParenImpCasts());
    }else if (auto uop = dyn_cast<UnaryOperator>(epr)){
      StringRef opcode=uop->getOpcodeStr(uop->getOpcode());
      //llvm:errs() << "unaryopcode : "<< opcode << " on line " << line << "\n";
      clang::Expr* uopr = uop->getSubExpr()->IgnoreParenImpCasts();
      if (opcode != "&" && opcode !="*"){
        wlist.push_back(uopr);
        continue;
      }
    }else if (auto callop = dyn_cast<CallExpr>(epr)){
      //const Expr* callee = callop->getCallee();
      if (auto callee = dyn_cast<const clang::NamedDecl>(callop->getCalleeDecl())){
        const string cname = callee->getNameAsString(); 
        if (mathcalls.find(cname) == mathcalls.end())
          Debug(llvm::errs() << "call expr (line " << line << " ): " << callee->getNameAsString() << "\n"); // non
        else {
          const string cname_ld = mathcalls.find(cname)->second;
          TheRewriter.ReplaceText(callop->getExprLoc(), cname.length(), cname_ld);
        }
      }
      for (const auto * epr : callop->arguments())
        if (!isa<CXXDefaultArgExpr>(epr))
          wlist.push_back(epr->IgnoreParenImpCasts());
    } else if ( string(epr->getStmtClassName()) == "IntegerLiteral" || string(epr->getStmtClassName()) == "FloatingLiteral"){
      // llvm::errs() << "an  interger/floating literal (line " << lRp->lineNum << " )\n"; // non
    } else {
      llvm::errs() << "failed to obtain the variable an assignment (line " << line << ") reads.\n"; 
    }  
  }
}

SourceLocation varScopeEnd(const VarDecl* vd, ASTContext* context){
  auto it = context->getParents(*vd).begin();
  const auto* stmt = it->get<clang::Stmt>();

  while(true){
    it = context->getParents(*stmt).begin();
    if(it == context->getParents(*stmt).end()){
      llvm::errs() << "failed to find the scope of the following variable:\n";
      vd->dump();
      exit(-1); 
    }
    const clang::CompoundStmt *aComSt = it->get<clang::CompoundStmt>();
    if(aComSt)
      return aComSt->getEndLoc();
    else
      stmt = it->get<clang::Stmt>();
  }

}

void _funcRecord::handleRegionEE(unsigned lstart, unsigned lend, Rewriter& TheRewriter){
  insertEntry = false;
  insertExit = false;

  set<const VarDecl*> regReads;
  for(unsigned line=lend; line>=lstart; line--){
    //llvm::errs() << "---DEBUG : handling region entry and exit: line " << line<<"\n"; 
    if(lineRs.find(line) != lineRs.end()){
      _lineRecord* lrd = lineRs[line];
      
      for (const auto * rvar : lrd->reads){
        const VarDecl* rd = dyn_cast<VarDecl>(rvar->getDecl());
        regReads.insert(rd);
      }

      for (const auto * wvar : lrd->writes){
        const VarDecl* wd = dyn_cast<VarDecl>(wvar->getDecl());
        if (regReads.find(wd)!=regReads.end() && newFPDels.find(wd) == newFPDels.end()){ // "read after write" variables that are not visited before
          const clang::Type* ty = wd->getType().getTypePtr();
          if (isDoubleArray(ty, context)) // double Array local variables
            continue;
          if (isDoublePointer(ty, context)) // double Array local variables
            continue;

          SourceLocation SL = wvar->getDecl()->getBeginLoc();
          unsigned decline = context->getFullLoc(SL).getSpellingLineNumber();
          
          string qualifiers = wd->getType().getQualifiers().getAsString();
          string newtype = (qualifiers=="")? typeTransTo: qualifiers+" "+typeTransTo;
          string ws = wvar->getNameInfo().getAsString();
          string wsH = ws+"_"+to_string(regLstart)+"_"+to_string(regLend)+"_H";

          //llvm::errs() << ws << "(declared on line " << decline <<") --> " << ws << "_H (" << newtype << ")\n";
          //llvm::errs() << "region <" << lstart <<","<<lend<<">\n";
          if (decline >= lstart && decline <=line){ //decls with "read after write"
            //const VarDecl *vd = dyn_cast<VarDecl>(wvar->getDecl());
            string typeName = wd->getType().getAsString();
            Debug(llvm::errs() << "Line " << decline << ": " << ws << " (" << typeName << ") -> " << ws << "_H (" << newtype << ")\n");
            TheRewriter.ReplaceText(wd->getSourceRange().getBegin(), typeName.length(), newtype);
            TheRewriter.ReplaceText(wd->getLocation(), ws.length(), wsH);
            
	    SourceLocation escope;
            if(const ParmVarDecl* pd=dyn_cast<ParmVarDecl>(wd)){
              escope = funcDel->getSourceRange().getEnd();
            } else { 
              escope = varScopeEnd(wd, context);
            }
            if(context->getFullLoc(escope).getSpellingLineNumber() > lend)
              regExit << typeName << " " << ws << " = " << wsH << ";\n";
 
            newFPDels[wd] = wsH; 
             
          } else { // "read after write"
            regEntry << newtype << " " << wsH << " = " << ws << ";\n"; 
	    SourceLocation escope;
            if(const ParmVarDecl* pd=dyn_cast<ParmVarDecl>(wd)){
              escope = funcDel->getSourceRange().getEnd();
            } else { 
              escope = varScopeEnd(wd, context);
            }
	  
            if(context->getFullLoc(escope).getSpellingLineNumber() > lend)
              regExit << ws << " = " << wsH << ";\n";
            newFPDels[wd] = wsH; 
          }
        }
      }
      
      for (const auto * dvar : lrd->vDels){
        if (dvar->hasInit() && regReads.find(dvar)!=regReads.end() && newFPDels.find(dvar) == newFPDels.end()){
          string dtypeName = dvar->getType().getAsString();
          string dqualifiers = dvar->getType().getQualifiers().getAsString();
          string dnewtype = (dqualifiers=="")? typeTransTo: dqualifiers+" "+typeTransTo;
          string ds = dvar->getNameAsString();
          string dsH = ds+"_"+to_string(regLstart)+"_"+to_string(regLend)+"_H";

          //SourceLocation dSL = dvar->getSourceRange().getBegin();
          //unsigned dline = context->getFullLoc(dSL).getSpellingLineNumber();
          //llvm::errs() << "Line " << dline << ": " << ds << " (" << dtypeName << ") -> " << ds << "_H (" << dnewtype << ")\n";

          TheRewriter.ReplaceText(dvar->getSourceRange().getBegin(), dtypeName.length(), dnewtype);
          TheRewriter.ReplaceText(dvar->getLocation(), ds.length(), dsH);
  
	  SourceLocation escope = varScopeEnd(dvar, context);
          if(context->getFullLoc(escope).getSpellingLineNumber() > lend)
            regExit << dtypeName << " " << ds << " = " << dsH << ";\n";
         
          newFPDels[dvar] = dsH; 
        }
      }
      
      unsigned int cnt=0;
      set<const VarDecl*> visited;
      for (const auto * svar : lrd->syncs){
        const VarDecl* sd = dyn_cast<VarDecl>(svar->getDecl());
        if (visited.find(sd)==visited.end() and newFPDels.find(sd)!=newFPDels.end()){
	  cnt += 1;
          visited.insert(sd);
        }
      }
      if (cnt>tmpNo) tmpNo = cnt;
    } // end of if
  } // end of for

  if (tmpNo>0){
    string suffix= "_"+to_string(regLstart)+"_"+to_string(regLend);
    regEntry << "double tmp1" << suffix;
    for (int i=2; i<=tmpNo;i++){
      regEntry << ", tmp" << to_string(i) << suffix;
    }
    regEntry << ";\n";
  }

}

void _funcRecord::transRegionDeclStmt(Rewriter& TheRewriter, const DeclStmt* delst){

  //SourceLocation SL = delst->getSourceRange().getBegin();
  //unsigned line = context->getFullLoc(SL).getSpellingLineNumber();

  const VarDecl *vd = dyn_cast<VarDecl>(*delst->decl_begin());
  string typeName = vd->getType().getAsString();
  
  const clang::Type* ty = vd->getType().getTypePtr();
  if (isDouble(ty, context)){ // double local variables
    for(const auto * vdI = delst->decl_begin(); vdI != delst->decl_end(); vdI++){
      const VarDecl *vdc = dyn_cast<VarDecl>(*vdI);
      if (vdc->hasInit()){
        const clang::Expr* epr = vdc->getInit()->IgnoreParenImpCasts();
        handleReads(TheRewriter, epr);
      }
    }
  }
          
}

void _funcRecord::transRegionWhileStmt(Rewriter& TheRewriter, const WhileStmt* wst){
  llvm::errs() << "Incomplete function : transRegionWhileStmt \n"; 
}
void _funcRecord::transRegionForStmt(Rewriter& TheRewriter, const ForStmt* forst){
  // for loops
  if(const Stmt* forBodyStmt = dyn_cast<Stmt>(forst->getBody())){
    transRegionStmts(TheRewriter, forBodyStmt);
    return;
  }
   
  const CompoundStmt *forBody = dyn_cast<CompoundStmt>(forst->getBody());
  CompoundStmt::const_body_iterator stmtI;
  for (stmtI =forBody->body_begin(); stmtI != forBody->body_end(); stmtI++){
    const Stmt * st = *stmtI;
    //st->dump();
    transRegionStmts(TheRewriter, st);
  }
}
void _funcRecord::transRegionIfStmt(Rewriter& TheRewriter, const IfStmt* ifst){
  // if statement
  if(insertEntry){
    const Expr* cond = ifst->getCond()->IgnoreParenImpCasts();
    handleReads(TheRewriter, cond);
  } 

  if(const Stmt* thenst = dyn_cast<Stmt>(ifst->getThen()))
    transRegionStmts(TheRewriter, thenst);
  else
    if(const CompoundStmt *thenBody = dyn_cast<CompoundStmt>(ifst->getThen())){
      CompoundStmt::const_body_iterator stmtI;
      for (stmtI =thenBody->body_begin(); stmtI != thenBody->body_end(); stmtI++){
        const Stmt * st = *stmtI;
        //st->dump();
        transRegionStmts(TheRewriter, st);
      }
    } // end of if-branch
  
  if (ifst->hasElseStorage()){
    if(const Stmt* elsest = dyn_cast<Stmt>(ifst->getElse()))
      transRegionStmts(TheRewriter, elsest);
    else
      if(const CompoundStmt *elseBody = dyn_cast<CompoundStmt>(ifst->getElse())){
        CompoundStmt::const_body_iterator stmtI;
        for (stmtI =elseBody->body_begin(); stmtI != elseBody->body_end(); stmtI++){
          const Stmt * st = *stmtI;
          transRegionStmts(TheRewriter, st);
        }
      } 
  } // end of else-branch

}

void _funcRecord::transRegionSwitchStmt(Rewriter& TheRewriter, const SwitchStmt* swst){
  llvm::errs() << "Incomplete function : transRegionSwitchStmt \n"; 
}

void _funcRecord::transRegionCallExprStmt(Rewriter& TheRewriter, const CallExpr* callep){
  SourceLocation SL = callep->getExprLoc();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();

  if (auto callee = dyn_cast<const clang::NamedDecl>(callep->getCalleeDecl())){
    const string cname = callee->getNameAsString(); 
    if (mathcalls.find(cname) == mathcalls.end())
      llvm::errs() << "call expr (line " << line << " ): " << callee->getNameAsString() << "\n"; // non
    else {
      const string cname_ld = mathcalls.find(cname)->second;
      TheRewriter.ReplaceText(callep->getExprLoc(), cname.length(), cname_ld);
    }
  }
  for (const auto * epr : callep->arguments())
    if (!isa<CXXDefaultArgExpr>(epr))
      //wlist.push_back(epr->IgnoreParenImpCasts());
      handleReads(TheRewriter, epr);

  // handle variables that require data synchronization
  handleRegionSyncs(TheRewriter, callep); 
}

void _funcRecord::handleRegionSyncs(Rewriter& TheRewriter, const Stmt* statement){
  //SourceLocation SL = statement->getExprLoc();
  SourceLocation SL = statement->getSourceRange().getBegin();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();

  _lineRecord* lrd = lineRs[line];
  if (lrd->syncs.size()==0)
    return;

  SourceRange range = statement->getSourceRange();
  unsigned int currNo = 0; 
  map<const VarDecl*, unsigned int> vSync;
  stringstream synEntry, synExit;
  synEntry << "{"; 
  for (const auto * svar : lrd->syncs){
    SourceLocation loc = svar->getExprLoc();
    string name = svar->getNameInfo().getAsString();
    if (loc<range.getBegin()||range.getEnd()<loc)
      continue; 

    //if (isa<ArraySubscriptExpr>(svar))
    //  continue;

    const VarDecl* sd = dyn_cast<VarDecl>(svar->getDecl());
    const clang::Type* ty= sd->getType().getTypePtr();
    if (!isDouble(ty, context))
      continue;

    string mytmp; 
    string suffix= "_"+to_string(regLstart)+"_"+to_string(regLend);
    if (vSync.find(sd)==vSync.end()){
      currNo += 1;
      vSync[sd] = currNo;
      mytmp = "tmp"+suffix+ to_string(currNo); 
      synEntry << mytmp << "=" << name << ";";
      synExit << name << "=" << mytmp << ";";
    }
    mytmp = "tmp"+ suffix+ to_string(vSync.find(sd)->second); 
    TheRewriter.ReplaceText(loc, name.length(), mytmp);
  }
  TheRewriter.InsertTextBefore(range.getBegin(), synEntry.str());
  //TheRewriter.InsertTextAfter(range.getEnd(), synExit.str());
 
  synExit << "}";
  SourceLocation exitSL = range.getEnd();
  unsigned exitLine = context->getFullLoc(exitSL).getSpellingLineNumber();
  unsigned off=0;

  if (const auto * bop = dyn_cast<BinaryOperator>(statement)){ 
    const clang::Expr* epr=bop->getRHS()->IgnoreImpCasts(); 
    //llvm::errs() << "---DEBUG : checking for binary operators.\n"; 
    while(true){
      if (auto bop = dyn_cast<BinaryOperator>(epr)){
        epr = bop->getRHS()->IgnoreImpCasts();
      }else if (auto cop = dyn_cast<ConditionalOperator>(epr)){
        epr = cop->getFalseExpr()->IgnoreImpCasts();
      }else if (auto uop = dyn_cast<UnaryOperator>(epr)){
        epr = uop->getSubExpr()->IgnoreImpCasts();
      }else if (auto readV = dyn_cast<DeclRefExpr>(epr)){
        off = readV->getNameInfo().getAsString().length();
        //llvm::errs() << "---DEBUG INFO:" << readV->getNameInfo().getAsString() << " on line" << exitLine <<"\n"; 
        break;
      }else if (auto intL = dyn_cast<IntegerLiteral>(epr)){
        //exitSL = intL->getEndLoc(); off=1;
        off=1; // for Laghos and varity tests
        break;
      }else if (auto fltL = dyn_cast<FloatingLiteral>(epr)){
        //llvm::SmallVector<char, 32> fltStr;
        //fltL->getValue().toString(fltStr, 32, true);   
        //llvm::errs() << "---DEBUG : float number " << fltStr << "(" << fltStr.size() <<").\n"; 
        //exitSL = fltL->getEndLoc(); off=1;
        off=11; // for Laghos and varity tests
        break;
      }else if (auto prt = dyn_cast<ParenExpr>(epr)){
        off = 1;
        break;
      } else {
        off = 1;
        break;
      }
    }
  }

  //while(exitSL.getLocWithOffset(off).printToString(context->getSourceManager())!=";") off++; 
  TheRewriter.InsertText(exitSL.getLocWithOffset(off+2), synExit.str(), true, true);
}

void _funcRecord::transRegionStmts(Rewriter& TheRewriter, const Stmt* statement){
  if (insertExit)
    return;

  //llvm::errs() << "---DEBUG : entered transRegionStmts\n";  
  SourceLocation SL = statement->getSourceRange().getBegin();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();
  //llvm::errs() << "---DEBUG : read line number:" << line <<"\n";  
  if(!insertEntry && line>=regLstart){
    insertEntry = true;
    TheRewriter.InsertText(SL.getLocWithOffset(0), regEntry.str(), false, true);
    Debug(llvm::errs() << "region transformation starts on line " << line << "\n");
  }
  if(line>=regLend+1){
    insertExit = true;
    if (cursor==NULL){
      Debug(llvm::errs() << "region transformation ends on line " << line << " without injection\n");
      return;
    }
    //SourceLocation exitSL = cursor->getSourceRange().getEnd();
    SourceLocation exitSL = cursor->getEndLoc();
    unsigned exitLine = context->getFullLoc(exitSL).getSpellingLineNumber();
    unsigned off=0;

    if (const auto * bop = dyn_cast<BinaryOperator>(cursor)){ 
      const clang::Expr* epr=bop->getRHS()->IgnoreImpCasts(); 
      //llvm::errs() << "---DEBUG : checking for binary operators.\n"; 
      while(true){
        if (auto bop = dyn_cast<BinaryOperator>(epr)){
          epr = bop->getRHS()->IgnoreImpCasts();
        }else if (auto cop = dyn_cast<ConditionalOperator>(epr)){
          epr = cop->getFalseExpr()->IgnoreImpCasts();
        }else if (auto uop = dyn_cast<UnaryOperator>(epr)){
          epr = uop->getSubExpr()->IgnoreImpCasts();
        }else if (auto readV = dyn_cast<DeclRefExpr>(epr)){
          off = readV->getNameInfo().getAsString().length();
          //llvm::errs() << "---DEBUG INFO:" << readV->getNameInfo().getAsString() << " on line" << exitLine <<"\n"; 
          break;
        }else if (auto intL = dyn_cast<IntegerLiteral>(epr)){
          //exitSL = intL->getEndLoc(); off=1;
          off=1; // for Laghos and varity tests
          break;
        }else if (auto fltL = dyn_cast<FloatingLiteral>(epr)){
          //llvm::SmallVector<char, 32> fltStr;
          //fltL->getValue().toString(fltStr, 32, true);   
          //llvm::errs() << "---DEBUG : float number " << fltStr << "(" << fltStr.size() <<").\n"; 
          //exitSL = fltL->getEndLoc(); off=1;
          off=11; // for Laghos and varity tests
          break;
        }else if (auto prt = dyn_cast<ParenExpr>(epr)){
          off = 1;
          break;
        } else {
          off = 1;
          break;
        }
      }
    }

    //while(exitSL.getLocWithOffset(off).printToString(context->getSourceManager())!=";") off++; 
    TheRewriter.InsertText(exitSL.getLocWithOffset(off+1), regExit.str(), true, true);
    Debug(llvm::errs() << "region transformation ends on line " << exitLine << "\n");
    return;
  }

  //cursor = statement; 
  string type = statement->getStmtClassName();
  if (type == "ReturnStmt") {
    if (insertEntry){
      auto rs = dyn_cast<const ReturnStmt>(statement);
      transWholeReturnStmt(TheRewriter, rs);
    }
  } else if (type == "WhileStmt") {
    auto ws = dyn_cast<WhileStmt>(statement);
    transRegionWhileStmt(TheRewriter, ws);
  } else if (type == "ForStmt") {
    auto fs = dyn_cast<const ForStmt>(statement);
    transRegionForStmt(TheRewriter, fs);
  } else if (type == "IfStmt") {
    auto is = dyn_cast<const IfStmt>(statement);
    transRegionIfStmt(TheRewriter, is);
  } else if (type == "SwitchStmt") {
    auto ss = dyn_cast<const SwitchStmt>(statement);
    transRegionSwitchStmt(TheRewriter, ss);
  } else if (type == "DeclStmt"){
    cursor = statement; 
    if (insertEntry){
      auto ds = dyn_cast<const DeclStmt>(statement);
      transRegionDeclStmt(TheRewriter, ds);
    }
  } else if (type == "BinaryOperator") {
    cursor = statement; 
    if (insertEntry){
      auto bs = dyn_cast<BinaryOperator>(statement);
      transWholeBinaryOpStmt(TheRewriter, bs);
    }
  } else if (type == "CompoundAssignOperator") {
    cursor = statement; 
    if (insertEntry){
      auto comas = dyn_cast<CompoundAssignOperator>(statement);
      transWholeCompoundAOpStmt(TheRewriter, comas);
    }
  } else if (type == "CompoundStmt") {
    auto cs = dyn_cast<const CompoundStmt>(statement);
    for (auto child : cs->children())
      transRegionStmts(TheRewriter, child);
  } else if (type == "CallExpr") {
    auto callep = dyn_cast<CallExpr>(statement);
    Debug(llvm::errs() << "call RegionCallExpr on line " << line << "\n");
    transRegionCallExprStmt(TheRewriter, callep);
  } else {
    llvm::errs() << "Unhandled Statement: " << type << " , line " << line << "\n"; 
  } 

}
void _funcRecord::transRegion(unsigned lstart, unsigned lend, Rewriter& TheRewriter, string myReal){
  outs() << "region transformation" << " <" << lstart << ", " << lend << ">\n";
  //typeTransTo = "long double";
  //typeTransTo = "__float128";
  typeTransTo = myReal;
  regLstart = lstart; regLend = lend;
  newFPDels.clear();
  regEntry.str(""); regExit.str("");
  insertEntry = false; insertExit = false;
  cursor=NULL;

  //handleFPParameters(TheRewriter);
  handleRegionEE(lstart, lend, TheRewriter); 

  const CompoundStmt *fBody = dyn_cast<CompoundStmt>(funcDel->getBody());
  CompoundStmt::const_body_iterator stmtI;
  for (stmtI =fBody->body_begin(); stmtI != fBody->body_end(); stmtI++){
    const Stmt * st = *stmtI;

    SourceLocation SL = st->getSourceRange().getBegin();
    unsigned line = context->getFullLoc(SL).getSpellingLineNumber();
    
    if(insertExit) 
      break;

    transRegionStmts(TheRewriter, st);

  }
}

void _funcRecord::transWholeReturnStmt(Rewriter& TheRewriter, const ReturnStmt* rst){
  const clang::Expr* epr = rst->getRetValue()->IgnoreParenImpCasts();

  handleReads(TheRewriter, epr);

  // handle variables that require data synchronization
  handleWholeSyncs(TheRewriter, rst); 
}
void _funcRecord::transWholeWhileStmt(Rewriter& TheRewriter, const WhileStmt* wst){
  //llvm::errs() << "Incomplete function : transWholeWhileStmt \n";

  const Expr* cond = wst->getCond()->IgnoreParenImpCasts();
  handleReads(TheRewriter, cond);
   
  if(const Stmt* dost = dyn_cast<Stmt>(wst->getBody()))
    transWholeStmts(TheRewriter, dost);
  else
    if(const CompoundStmt *doBody = dyn_cast<CompoundStmt>(wst->getBody())){
      CompoundStmt::const_body_iterator stmtI;
      for (stmtI =doBody->body_begin(); stmtI != doBody->body_end(); stmtI++){
        const Stmt * st = *stmtI;
        //st->dump();
        transWholeStmts(TheRewriter, st);
      }
    }
}
void _funcRecord::transWholeForStmt(Rewriter& TheRewriter, const ForStmt* forst){
  // for loops
  if(const Stmt* forBodyStmt = dyn_cast<Stmt>(forst->getBody())){
    transWholeStmts(TheRewriter, forBodyStmt);
    return;
  }
   
  const CompoundStmt *forBody = dyn_cast<CompoundStmt>(forst->getBody());
  CompoundStmt::const_body_iterator stmtI;
  for (stmtI =forBody->body_begin(); stmtI != forBody->body_end(); stmtI++){
    const Stmt * st = *stmtI;
    //st->dump();
    transWholeStmts(TheRewriter, st);
  }
}
void _funcRecord::transWholeIfStmt(Rewriter& TheRewriter, const IfStmt* ifst){
  // if statement
  const Expr* cond = ifst->getCond()->IgnoreParenImpCasts();
  handleReads(TheRewriter, cond);
   
  if(const Stmt* thenst = dyn_cast<Stmt>(ifst->getThen()))
    transWholeStmts(TheRewriter, thenst);
  else
    if(const CompoundStmt *thenBody = dyn_cast<CompoundStmt>(ifst->getThen())){
      CompoundStmt::const_body_iterator stmtI;
      for (stmtI =thenBody->body_begin(); stmtI != thenBody->body_end(); stmtI++){
        const Stmt * st = *stmtI;
        //st->dump();
        transWholeStmts(TheRewriter, st);
      }
    }

  if (ifst->hasElseStorage()){
    if(const Stmt* elsest = dyn_cast<Stmt>(ifst->getElse()))
      transWholeStmts(TheRewriter, elsest);
    else
      if(const CompoundStmt *elseBody = dyn_cast<CompoundStmt>(ifst->getElse())){
        CompoundStmt::const_body_iterator stmtI;
        for (stmtI =elseBody->body_begin(); stmtI != elseBody->body_end(); stmtI++){
          const Stmt * st = *stmtI;
          //st->dump();
          transWholeStmts(TheRewriter, st);
        }
      }
  } // end of else branch
 
}

void _funcRecord::transWholeSwitchStmt(Rewriter& TheRewriter, const SwitchStmt* swst){
  llvm::errs() << "Incomplete function : transWholeSwitchStmt \n";

}
void _funcRecord::transWholeDeclStmt(Rewriter& TheRewriter, const DeclStmt* delst){
  //SourceLocation SL = delst->getSourceRange().getBegin();
  //unsigned line = context->getFullLoc(SL).getSpellingLineNumber();

  const VarDecl *vd = dyn_cast<VarDecl>(*delst->decl_begin());
  string typeName = vd->getType().getAsString();
  string qualifiers = vd->getType().getQualifiers().getAsString();
  
  const clang::Type* ty = vd->getType().getTypePtr();
  if (isDouble(ty, context) && newFPDels.find(vd) == newFPDels.end()){ // double local variables
    string newtype = (qualifiers=="")? typeTransTo:qualifiers+" "+typeTransTo;
    TheRewriter.ReplaceText(vd->getSourceRange().getBegin(), typeName.length(), newtype);
    //outs() << "Line " << line << ": double (" << qualifiers << ") "<< vd->getNameAsString() << "\n";        
    for(const auto * vdI = delst->decl_begin(); vdI != delst->decl_end(); vdI++){
      const VarDecl *vdc = dyn_cast<VarDecl>(*vdI);
      string vcname = vdc->getNameAsString();
      newFPDels[vdc] = vcname;
      if (vdc->hasInit()){
        const clang::Expr* epr = vdc->getInit()->IgnoreParenImpCasts();
        handleReads(TheRewriter, epr);
      }
    }
  }

  // handle variables that require data synchronization
  handleWholeSyncs(TheRewriter, delst); 
}

void _funcRecord::transWholeBinaryOpStmt(Rewriter& TheRewriter, const BinaryOperator* bst){

  if(!bst->isAssignmentOp())
    return;
  
  SourceLocation SL = bst->getExprLoc();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();
  const clang::Type* ty = bst->getType().getTypePtr();
  if (isDouble(ty, context)){ // double 
    const clang::Expr* lhs = bst->getLHS()->IgnoreParenImpCasts(); // obtain the variable it writes
    if (auto arr = dyn_cast<ArraySubscriptExpr>(lhs)){
      lhs = arr->getBase()->IgnoreParenImpCasts();
    }
    if (auto writeV = dyn_cast<DeclRefExpr>(lhs)){
      const clang::Type* ty= writeV->getDecl()->getType().getTypePtr();
      if (isDoubleBase(ty, context)){
        const VarDecl* wdel = dyn_cast<VarDecl>(writeV->getDecl()); 
        string vname = writeV->getNameInfo().getAsString();
        map<const VarDecl*, string>::iterator it = newFPDels.find(wdel);
        if (it != newFPDels.end()){
          string newvname = newFPDels[wdel];
          TheRewriter.ReplaceText(writeV->getExprLoc(), vname.length(), newvname);
        }
      }
    } else {
      llvm::errs() << "failed to obtain the variable an assignment (line " << line << ") writes to.\n"; 
    }
   
    const clang::Expr* rhs = bst->getRHS()->IgnoreParenImpCasts();
    handleReads(TheRewriter, rhs);
  }

  // handle variables that require data synchronization
  handleWholeSyncs(TheRewriter, bst); 
}
void _funcRecord::transWholeCompoundAOpStmt(Rewriter& TheRewriter, const CompoundAssignOperator* comast){
  SourceLocation SL = comast->getSourceRange().getBegin();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();
  
  const clang::Type* ty = comast->getType().getTypePtr();
  if (isDouble(ty, context)){ // double 
    const clang::Expr* lhs = comast->getLHS()->IgnoreParenImpCasts(); // obtain the variable it writes
    if (auto arr = dyn_cast<ArraySubscriptExpr>(lhs)){
      lhs = arr->getBase()->IgnoreParenImpCasts();
    }
    if (auto writeV = dyn_cast<DeclRefExpr>(lhs)){
      const clang::Type* ty= writeV->getDecl()->getType().getTypePtr();
      if (isDoubleBase(ty, context)){
        const VarDecl* wdel = dyn_cast<VarDecl>(writeV->getDecl()); 
        string vname = writeV->getNameInfo().getAsString();
        map<const VarDecl*, string>::iterator it = newFPDels.find(wdel);
        if (it != newFPDels.end()){
          string newvname = newFPDels[wdel];
          TheRewriter.ReplaceText(writeV->getExprLoc(), vname.length(), newvname);
        }
      }
    } else {
      llvm::errs() << "failed to obtain the variable an assignment (line " << line << ") writes to.\n"; 
    }
   
    const clang::Expr* rhs = comast->getRHS()->IgnoreParenImpCasts();
    handleReads(TheRewriter, rhs);
  }

  // handle variables that require data synchronization
  handleWholeSyncs(TheRewriter, comast); 
}

string _funcRecord::enhanceFormatSpecifierPrecision(string printf_format_specifier, vector<int> paramTransformed){
  // This function converts a given format specifier from double to long doubel
  // Ex "%.15g" to "%.15Lg"
  int param_number=1;
  vector<tuple<string, string, int>> format_specifier_info_list;
  tuple<string,string,int> format_specifier_info;
  string format_specifier, updated_format_specifier;
  regex e(R"(%(?:(?:[-+0 #]{0,5})(?:\d+|\*)?(?:\.(?:\d+|\*))?(?:h|l|ll|w|L|I|I32|I64)?[cCdiouxXeEfgGaAnpsSZ]))");
  sregex_iterator iter(printf_format_specifier.begin(), printf_format_specifier.end(), e);
  sregex_iterator end;
  for(auto i = iter; i!=end;i++){
    updated_format_specifier = "";
    format_specifier = (*i).str();

    regex exp(R"([eEfFgGaA])");
    sregex_iterator regex_iter(format_specifier.begin(), format_specifier.end(), exp);
    if(paramTransformed[param_number]==1){
        if(format_specifier.find("L")!=string::npos || format_specifier.find("l")!=string::npos)
        {
            continue;
        }
        int position=(*regex_iter).position();
        updated_format_specifier = format_specifier;
        updated_format_specifier.insert(position,"L");

        format_specifier_info_list.push_back(make_tuple(format_specifier,updated_format_specifier,(*i).position()));
    }
    param_number++;
  }
  for(int i=format_specifier_info_list.size()-1;i>=0;i--){
      format_specifier_info = format_specifier_info_list[i];
      printf_format_specifier.replace(get<2>(format_specifier_info), get<0>(format_specifier_info).size(), get<1>(format_specifier_info));
  }
  return printf_format_specifier;

}

int _funcRecord::handleFuncParamReads(Rewriter& TheRewriter, const clang::Expr* epr){
  if (epr==nullptr)
    return 0;
  int is_transformed =0;
  SourceLocation SL = epr->getExprLoc();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();

  vector<const clang::VarDecl*> synclist;

  vector<const clang::Expr*> wlist;
  wlist.push_back(epr);

  while (!wlist.empty()){
    epr = wlist.back(); wlist.pop_back();
    if (auto arr = dyn_cast<ArraySubscriptExpr>(epr)){
      epr = arr->getBase()->IgnoreParenImpCasts();
    }
    if (auto readV = dyn_cast<DeclRefExpr>(epr)){
      const clang::Type* ty= readV->getDecl()->getType().getTypePtr();
      if (isDoubleBase(ty, context)){
        
        const VarDecl* vdel = dyn_cast<VarDecl>(readV->getDecl()); 
        string vname = readV->getNameInfo().getAsString();
        map<const VarDecl*, string>::iterator it = newFPDels.find(vdel);
        if (it == newFPDels.end()){
          // pass
        }else{
          string newvname = newFPDels[vdel];
          TheRewriter.ReplaceText(readV->getExprLoc(), vname.length(), newvname);
          is_transformed=1; 
        }
      }
    }else if (auto bop = dyn_cast<BinaryOperator>(epr)){
      wlist.push_back(bop->getLHS()->IgnoreParenImpCasts());
      wlist.push_back(bop->getRHS()->IgnoreParenImpCasts());
    }else if (auto cop = dyn_cast<ConditionalOperator>(epr)){
      wlist.push_back(cop->getCond()->IgnoreParenImpCasts());
      wlist.push_back(cop->getTrueExpr()->IgnoreParenImpCasts());
      wlist.push_back(cop->getFalseExpr()->IgnoreParenImpCasts());
    }else if (auto uop = dyn_cast<UnaryOperator>(epr)){
      StringRef opcode=uop->getOpcodeStr(uop->getOpcode());
      
      clang::Expr* uopr = uop->getSubExpr()->IgnoreParenImpCasts();
      if (opcode != "&" && opcode !="*"){
        wlist.push_back(uopr);
        continue;
      }
    }else if (auto callop = dyn_cast<CallExpr>(epr)){
      
      if (auto callee = dyn_cast<const clang::NamedDecl>(callop->getCalleeDecl())){
        const string cname = callee->getNameAsString(); 
        
        if (mathcalls.find(cname) == mathcalls.end())
          Debug(llvm::errs() << "call expr (line " << line << " ): " << callee->getNameAsString() << "\n"); // non
        else {
          const string cname_ld = mathcalls.find(cname)->second;
          TheRewriter.ReplaceText(callop->getExprLoc(), cname.length(), cname_ld);
          is_transformed=1;
        }
      }
      for (const auto * epr : callop->arguments())
        if (!isa<CXXDefaultArgExpr>(epr))
          wlist.push_back(epr->IgnoreParenImpCasts());
    } else if ( string(epr->getStmtClassName()) == "IntegerLiteral" || string(epr->getStmtClassName()) == "FloatingLiteral"){
      
    } else {
      llvm::errs() << "failed to obtain the variable an assignment (line " << line << ") reads.\n"; 
    }  
  }
  return is_transformed;
}

void _funcRecord::transWholeCallExprStmt(Rewriter& TheRewriter, const CallExpr* callep){
  SourceLocation SL = callep->getExprLoc();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();
  vector<int> paramTransformed;

  if (auto callee = dyn_cast<const clang::NamedDecl>(callep->getCalleeDecl())){
    const string cname = callee->getNameAsString(); 
    if (mathcalls.find(cname) == mathcalls.end()){
      llvm::errs() << "call expr (line " << line << " ): " << callee->getNameAsString() << "\n"; // non
      
      if(transWholeFunc && callee->getNameAsString()=="printf")
      {
        for(auto *epr : callep->arguments()){
          if (auto temp = dyn_cast<ImplicitCastExpr>(epr))
          {
            epr = epr->IgnoreImpCasts();
            int is_transformed = handleFuncParamReads(TheRewriter, epr);
            paramTransformed.push_back(is_transformed);
          }
          else {
            int is_transformed = handleFuncParamReads(TheRewriter, epr);
            paramTransformed.push_back(is_transformed);
          }
        }
        string printf_format;
        // Get printf format specifier
        clang::LangOptions langOpts;
        langOpts.CPlusPlus = true;
        clang::PrintingPolicy policy(langOpts);
        raw_string_ostream stream(printf_format);
        callep->getArg(0)->printPretty(stream, 0, policy);
        string updated_format_specifier = enhanceFormatSpecifierPrecision(stream.str(), paramTransformed);
        TheRewriter.ReplaceText(callep->getArg(0)->getExprLoc(),stream.str().length(),updated_format_specifier);
      }
    }
      
      
    else {
      const string cname_ld = mathcalls.find(cname)->second;
      TheRewriter.ReplaceText(callep->getExprLoc(), cname.length(), cname_ld);
    }
  }

  // handle variables that require data synchronization
  handleWholeSyncs(TheRewriter, callep); 
}

void _funcRecord::handleWholeSyncs(Rewriter& TheRewriter, const Stmt* statement){
  //SourceLocation SL = statement->getExprLoc();
  SourceLocation SL = statement->getSourceRange().getBegin();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();

  _lineRecord* lrd = lineRs[line];
  if (lrd->syncs.size()==0)
    return;

  SourceRange range = statement->getSourceRange();
  unsigned int currNo = 0; 
  map<const VarDecl*, unsigned int> vSync;
  stringstream synEntry, synExit;
  synEntry << "{"; 
  for (const auto * svar : lrd->syncs){
    SourceLocation loc = svar->getExprLoc();
    string name = svar->getNameInfo().getAsString();
    if (loc<range.getBegin()||range.getEnd()<loc)
      continue; 

    //if (isa<ArraySubscriptExpr>(svar))
    //  continue;

    const VarDecl* sd = dyn_cast<VarDecl>(svar->getDecl());
    const clang::Type* ty= sd->getType().getTypePtr();
    if (!isDouble(ty, context))
      continue;

    string mytmp; 
    if (vSync.find(sd)==vSync.end()){
      currNo += 1;
      vSync[sd] = currNo;
      mytmp = "tmp"+ to_string(currNo); 
      synEntry << mytmp << "=" << name << ";";
      synExit << name << "=" << mytmp << ";";
    }
    mytmp = "tmp"+ to_string(vSync.find(sd)->second); 
    TheRewriter.ReplaceText(loc, name.length(), mytmp);
  }
  TheRewriter.InsertTextBefore(range.getBegin(), synEntry.str());
  //TheRewriter.InsertTextAfter(range.getEnd(), synExit.str());
 
  synExit << "}";
  SourceLocation exitSL = range.getEnd();
  unsigned exitLine = context->getFullLoc(exitSL).getSpellingLineNumber();
  unsigned off=0;

  if (const auto * bop = dyn_cast<BinaryOperator>(statement)){ 
    const clang::Expr* epr=bop->getRHS()->IgnoreImpCasts(); 
    //llvm::errs() << "---DEBUG : checking for binary operators.\n"; 
    while(true){
      if (auto bop = dyn_cast<BinaryOperator>(epr)){
        epr = bop->getRHS()->IgnoreImpCasts();
      }else if (auto cop = dyn_cast<ConditionalOperator>(epr)){
        epr = cop->getFalseExpr()->IgnoreImpCasts();
      }else if (auto uop = dyn_cast<UnaryOperator>(epr)){
        epr = uop->getSubExpr()->IgnoreImpCasts();
      }else if (auto readV = dyn_cast<DeclRefExpr>(epr)){
        off = readV->getNameInfo().getAsString().length();
        //llvm::errs() << "---DEBUG INFO:" << readV->getNameInfo().getAsString() << " on line" << exitLine <<"\n"; 
        break;
      }else if (auto intL = dyn_cast<IntegerLiteral>(epr)){
        //exitSL = intL->getEndLoc(); off=1;
        off=1; // for Laghos and varity tests
        break;
      }else if (auto fltL = dyn_cast<FloatingLiteral>(epr)){
        //llvm::SmallVector<char, 32> fltStr;
        //fltL->getValue().toString(fltStr, 32, true);   
        //llvm::errs() << "---DEBUG : float number " << fltStr << "(" << fltStr.size() <<").\n"; 
        //exitSL = fltL->getEndLoc(); off=1;
        off=11; // for Laghos and varity tests
        break;
      }else if (auto prt = dyn_cast<ParenExpr>(epr)){
        off = 1;
        break;
      } else {
        off = 1;
        break;
      }
    }
  }

  //while(exitSL.getLocWithOffset(off).printToString(context->getSourceManager())!=";") off++; 
  TheRewriter.InsertText(exitSL.getLocWithOffset(off+2), synExit.str(), true, true);
}

void _funcRecord::transWholeStmts(Rewriter& TheRewriter, const Stmt* statement){
  SourceLocation SL = statement->getSourceRange().getBegin();
  unsigned line = context->getFullLoc(SL).getSpellingLineNumber();
 
  string type = statement->getStmtClassName();
  if (type == "ReturnStmt") {
    auto rs = dyn_cast<const ReturnStmt>(statement);
    transWholeReturnStmt(TheRewriter, rs);
  } else if (type == "WhileStmt") {
    auto ws = dyn_cast<WhileStmt>(statement);
    transWholeWhileStmt(TheRewriter, ws);
  } else if (type == "ForStmt") {
    auto fs = dyn_cast<const ForStmt>(statement);
    transWholeForStmt(TheRewriter, fs);
  } else if (type == "IfStmt") {
    auto is = dyn_cast<const IfStmt>(statement);
    transWholeIfStmt(TheRewriter, is);
  } else if (type == "SwitchStmt") {
    auto ss = dyn_cast<const SwitchStmt>(statement);
    transWholeSwitchStmt(TheRewriter, ss);
  } else if (type == "DeclStmt"){
    auto ds = dyn_cast<const DeclStmt>(statement);
    transWholeDeclStmt(TheRewriter, ds);
  } else if (type == "BinaryOperator") {
    auto bs = dyn_cast<BinaryOperator>(statement);
    transWholeBinaryOpStmt(TheRewriter, bs);
  } else if (type == "CompoundAssignOperator") {
    auto comas = dyn_cast<CompoundAssignOperator>(statement);
    transWholeCompoundAOpStmt(TheRewriter, comas);
  } else if (type == "CompoundStmt") {
    auto cs = dyn_cast<const CompoundStmt>(statement);
    for (auto child : cs->children())
      transWholeStmts(TheRewriter, child);
  } else if (type == "CallExpr") {
    auto callep = dyn_cast<CallExpr>(statement);
    transWholeCallExprStmt(TheRewriter, callep);
  } else {
    llvm::errs() << "Unhandled Statement: " << type << " , line " << line << "\n"; 
  } 

}
 
void _funcRecord::transWhole(Rewriter& TheRewriter, string myReal){
  //typeTransTo = "long double";
  //typeTransTo = "__float128";
  typeTransTo = myReal;
  newFPDels.clear();

  // add global temporary variables; 
  map<unsigned, _lineRecord*>::iterator it=lineRs.begin();
  while(it!=lineRs.end()){
    _lineRecord* lrd = it->second;
    unsigned int cnt=0;
    set<const VarDecl*> visited;
    for (const auto * svar : lrd->syncs){
      const VarDecl* sd = dyn_cast<VarDecl>(svar->getDecl());
      const clang::Type* ty= sd->getType().getTypePtr();
      if (isDoubleBase(ty, context) & visited.find(sd)==visited.end()){
        cnt += 1;
        visited.insert(sd);
      }
    }
    if (cnt>tmpNo) tmpNo = cnt;
    it++;
  } // end of while

  if (tmpNo>0){
    regEntry << "double tmp1";
    for (int i=2; i<=tmpNo;i++){
      regEntry << ", tmp" << to_string(i);
    }
    regEntry << ";\n";
  }

  handleFPParameters(TheRewriter);

  const CompoundStmt *fBody = dyn_cast<CompoundStmt>(funcDel->getBody());
  CompoundStmt::const_body_iterator stmtI;
  for (stmtI =fBody->body_begin(); stmtI != fBody->body_end(); stmtI++){
    const Stmt * st = *stmtI;
    transWholeStmts(TheRewriter, st);

    }
}

//==================
//print
//==================

void _funcRecord::printFuncRecord(string filename){
  ofstream fout (filename, ofstream::out);
  fout << "{\n";

  fout << "  \"funcName\" :" << " \"" << funcName << "\",\n";
  fout << "  \"fileName\" :" << " \"" << fileName << "\",\n";
  	
  fout << "  \"fpParameters\" : [";
  for (const auto * parameter : fpparalist){
    string s = parameter->getNameAsString();
    if (parameter == *fpparalist.begin()) 
      fout << " \"" << s << "\"";
    else	
      fout << ", \"" << s << "\"";
  }
  fout << "],\n";

  fout << "  \"fpPointerParameters\" : [";
  for (const auto * parameter : fpPointerparalist){
    string s = parameter->getNameAsString();
    if (parameter == *fpPointerparalist.begin()) 
      fout << " \"" << s << "\"";
    else	
      fout << ", \"" << s << "\"";
  }
  fout << "],\n";

  fout << "  \"fpVars\" : [";
  for (const auto * parameter : fpvarlist){
    string s = parameter->getNameAsString();
    if (parameter == *fpvarlist.begin()) 
      fout << " \"" << s << "\"";
    else	
      fout << ", \"" << s << "\"";
  }
  fout << "],\n";

  fout << "  \"fpPointerVars\" : [";
  for (const auto * parameter : fpPointervarlist){
    string s = parameter->getNameAsString();
    if (parameter == *fpPointervarlist.begin()) 
      fout << " \"" << s << "\"";
    else       
      fout << ", \"" << s << "\"";
  }
  fout << "],\n";

  fout << "  \"forLoops\" : [ ";
  for (vector<tuple<unsigned, unsigned>>::iterator forit=forloops.begin(); forit!=forloops.end(); forit++){
    if ((forit == forloops.begin()))
      fout << " [ " << std::get<0>(*forit) << ", " << std::get<1>(*forit)<< "]";
    else 
      fout << ", [ " << std::get<0>(*forit) << ", " << std::get<1>(*forit)<< "]";
  }
  fout << " ],\n";

  fout << "  \"bbList\" : {";
  for (map<unsigned, tuple<unsigned, unsigned>>::iterator it=bblist.begin(); it!=bblist.end(); it++){
    unsigned bID = it->first;
    if ((it == bblist.begin()))
      fout << "\n    \"" << bID << "\": ";
    else 
      fout << ",\n    \"" << bID << "\": ";
   
    fout << "[ " << std::get<0>(it->second) << ", " << std::get<1>(it->second) << "]";
  }
  fout << "  }\n";

  fout << "}";
  fout.close();

  ofstream flineout (filename+"-lines", ofstream::out);
  flineout << "{\n";
  flineout.close();

  for(map<unsigned, _lineRecord*>::iterator lineit=lineRs.begin(); lineit!=lineRs.end(); lineit++){
    lineit->second->printLineRecord(filename+"-lines");
  }
   
  ofstream flineouta (filename+"-lines", ofstream::app);
  flineouta << "}";
  flineouta.close();
}

