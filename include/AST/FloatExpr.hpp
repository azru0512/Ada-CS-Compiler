#ifndef _FLOATEXPR_HPP_
#define _FLOATEXPR_HPP_


#include "AST/LiteralExpr.hpp"
#include "Type/FloatType.hpp"
#include "llvm/ADT/APFloat.h"
#include "llvm/Constants.h"
#include "llvm/LLVMContext.h"

// 類別 FlotExpr
//
// 代表 float literal
class FloatExpr : public LiteralExpr
{
public :
  explicit FloatExpr(double value)
  : LiteralExpr(new FloatType()),
    value_(value)
  {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    return llvm::ConstantFP::get(llvm::getGlobalContext(),
      llvm::APFloat(value_));
  }

private :
  double value_;
};

#endif
