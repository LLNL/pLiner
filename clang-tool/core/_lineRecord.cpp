#include"_lineRecord.h"

#include <iostream>
#include <fstream>

void _lineRecord::addVDel(const VarDecl* vd){
  vDels.push_back(vd);
}

void _lineRecord::addRead(const DeclRefExpr* df){
  reads.push_back(df);
}

void _lineRecord::addWrite(const DeclRefExpr* df){
  writes.push_back(df);
}

void _lineRecord::addCall(const CallExpr* cl){
  calls.push_back(cl);
}

void _lineRecord::addSync(const DeclRefExpr* df){
  syncs.push_back(df);
}

void _lineRecord::printLineRecord(string filename){
  ofstream fout (filename, ofstream::app);
  fout << "  " << lineNum << " : {\n";
  
  fout << "    \"vDels\" : [";
  for (const auto * var : vDels){
    string s = var->getNameAsString();
    if (var == *vDels.begin()) 
      fout << " \"" << s << "\"";
    else	
      fout << ", \"" << s << "\"";
  }
  fout << "],\n";

  fout << "    \"reads\" : [";
  for (const auto * rvar : reads){
    string s = rvar->getNameInfo().getAsString();
    if (rvar == *reads.begin()) 
      fout << " \"" << s << "\"";
    else	
      fout << ", \"" << s << "\"";
  }
  fout << "],\n";

  fout << "    \"writes\" : [";
  for (const auto * wvar : writes){
    string s = wvar->getNameInfo().getAsString();
    if (wvar == *writes.begin()) 
      fout << " \"" << s << "\"";
    else	
      fout << ", \"" << s << "\"";
  }
  fout << "],\n";

  fout << "    \"calls\" : [";
  for (const auto * call : calls){
    if (auto callee = dyn_cast<const clang::NamedDecl>(call->getCalleeDecl())){
      string s = callee->getNameAsString();
      if (call == *calls.begin()) 
        fout << " \"" << s << "\"";
      else	
        fout << ", \"" << s << "\"";
    }
  }
  fout << "],\n";

 fout << "    \"syncs\" : [";
  for (const auto * svar : syncs){
    string s = svar->getNameInfo().getAsString();
    if (svar == *syncs.begin()) 
      fout << " \"" << s << "\"";
    else	
      fout << ", \"" << s << "\"";
  }
  fout << "]\n";


  fout << "  }\n";
  fout.close();
} 
