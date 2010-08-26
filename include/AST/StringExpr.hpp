#ifndef _STRINGEXPR_HPP_
#define _STRINGEXPR_HPP_


#include "AST/LiteralExpr.hpp"
#include "Type/StringType.hpp"
#include <string>
#include <iostream>

class StringExpr : public LiteralExpr
{
public :
  explicit StringExpr(const std::string &value)
  : LiteralExpr(new StringType()),
    value_(value)
  {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    return builder.CreateGlobalString(value_.c_str(), "kerker"); 
  }

private :
  std::string value_;
};

#endif
