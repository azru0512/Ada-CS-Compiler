#ifndef _STRINGEXPR_HPP_
#define _STRINGEXPR_HPP_


#include "AST/LiteralExpr.hpp"
#include "Type/StringType.hpp"
#include "llvm/Constants.h"
#include <string>

class StringExpr : public LiteralExpr
{
public :
  explicit StringExpr(const std::string &value)
  : LiteralExpr(new StringType()),
    value_(value)
  {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    return llvm::ConstantArray::get(llvm::getGlobalContext(), "haha");
  }

private :
  std::string value_;
};

#endif
