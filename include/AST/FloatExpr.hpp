#ifndef _FLOATEXPR_HPP_
#define _FLOATEXPR_HPP_


#include "AST/LiteralExpr.hpp"
#include "llvm/ADT/APFloat.h"
#include "llvm/Constants.h"
#include "llvm/LLVMContext.h"

/**
 * Class FloatExpr
 * - 代表 Ada/CS 的 float literal
 */
class FloatExpr : public LiteralExpr
{
public :
  FloatExpr(double value) : value_(value) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    return llvm::ConstantFP::get(llvm::getGlobalContext(),
      llvm::APFloat(value_));
  }

private :
  double value_;
};

#endif
