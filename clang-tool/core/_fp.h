#ifndef _FP_DEBUGGER_FP_HEADER
#define _FP_DEBUGGER_FP_HEADER

#include "clang/AST/Type.h"
#include "clang/AST/ASTContext.h"

using namespace clang;
using namespace std;

#define DEBUG 1

#ifdef DEBUG 
#define Debug(x) (x)
#else 
#define Debug(x) do{}while(0)
#endif

bool isDouble(const Type* ty, ASTContext* context){
  if (ty->isFloatingType() & (context->getTypeSize(ty)==64)) 
    return true;
  else
    return false; 
}

bool isDoublePointer(const Type* ty, ASTContext* context){
  if (ty->isPointerType()){
    const clang::Type* pty = ty->getPointeeType().getTypePtr(); 
    if(pty->isFloatingType() & (context->getTypeSize(pty)==64)) 
      return true;
  }
  return false;
}

bool isDoubleArray(const Type* ty, ASTContext* context){
  if (const clang::ArrayType* vty = ty->getAsArrayTypeUnsafe())
    if (context->getTypeSize(vty->getElementType().getTypePtr())==64)
      return true;
  return false;
}

bool isDoubleBase(const Type* ty, ASTContext* context){
  if (isDouble(ty, context) || isDoublePointer(ty, context) || isDoubleArray(ty, context))
    return true;
  else
    return false;
}

const map<std::string, std::string> mathcalls = {
  {"fabs", "fabsl"},
  {"fma",  "fmal"},
  {"fmin", "fminl"},
  {"fmax", "fmaxl"},
  {"fmod", "fmodl"},
  {"fdim", "fdiml"},
  {"sin",  "sinl"},
  {"asin", "asinl"},
  {"sinh", "sinhl"},
  {"asinh", "asinhl"},
  {"cos",  "cosl"},
  {"acos", "acosl"},
  {"cosh", "coshl"},
  {"acosh", "acoshl"},
  {"tan",  "tanl"},
  {"atan", "atanl"},
  {"atan2", "atan2l"},
  {"tanh", "tanhl"},
  {"atanh", "atanhl"},
  {"exp",  "expl"},
  {"exp2", "exp2l"},
  {"expml", "expmll"},
  {"log",  "logl"},
  {"log2", "log2l"},
  {"log10", "log10l"},
  {"loglp", "loglpl"},
  {"pow",  "powl"},
  {"sqrt", "sqrtl"},
  {"cbrt", "cbrtl"},
  {"hypot", "hypotl"},
  {"frexp", "frexpl"},
  {"ldexp", "ldexpl"},
  {"scalbn", "scalbnl"},
  {"scalbln", "scalblnl"},
  {"ilogb", "ilogbl"},
  {"logb",  "logbl"},
  {"nextafter", "nextafterl"},
  {"nexttoward", "nexttowardl"},
  {"copysign", "copysignl"},
  {"ceil",  "ceill"},
  {"floor", "floorl"},
  {"trunc", "truncl"},
  {"round", "roundl"},
  {"lround", "lroundl"},
  {"llround", "llroundl"},
  {"rint",   "rintl"},
  {"lrint",  "lrintl"},
  {"llrint", "llrintl"},
  {"nearbyint", "nearbyintl"},
  {"erf",  "erfl"},
  {"erfc", "erfcl"},
  {"tgamma", "tgammal"},
  {"lgamma", "lgammal"}
};
#endif
