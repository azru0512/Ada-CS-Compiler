#ifndef _INTEGEREXPR_HPP_
#define _INTEGEREXPR_HPP_


#include "AST/LiteralExpr.hpp"
#include "Type/IntType.hpp"
#include "llvm/Constants.h"
#include "llvm/LLVMContext.h"
#include "llvm/Type.h"

// 類別 IntegerExpr
//
// 代表 integer literal
class IntegerExpr : public LiteralExpr
{
public :
  explicit IntegerExpr(long long value)
  : LiteralExpr(new IntType()),
    value_(value)
  {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    return llvm::ConstantInt::get(llvm::Type::getInt64Ty(
      llvm::getGlobalContext()), value_, true);
  }

private :
  long long value_;
};

#endif
