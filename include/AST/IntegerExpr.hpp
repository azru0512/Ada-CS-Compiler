#ifndef _INTEGEREXPR_HPP_
#define _INTEGEREXPR_HPP_


#include "AST/LiteralExpr.hpp"
#include "llvm/Constants.h"
#include "llvm/LLVMContext.h"
#include "llvm/Type.h"

/**
 * Class IntegerExpr
 * - 代表 integer literal
 */  
class IntegerExpr : public LiteralExpr
{
public :
  IntegerExpr(long long value) : value_(value) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    return llvm::ConstantInt::get(llvm::Type::getInt64Ty(
      llvm::getGlobalContext()), value_, true);
  }

private :
  long long value_; ///< 內部用 C++ 的 long long 變數儲存其值。
};

#endif
