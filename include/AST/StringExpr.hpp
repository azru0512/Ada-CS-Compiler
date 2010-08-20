#ifndef _STRINGEXPR_HPP_
#define _STRINGEXPR_HPP_


#include "AST/LiteralExpr.hpp"
#include <string>

class StringExpr : public LiteralExpr
{
public :
  explicit StringExpr(const std::string &value) : value_(value) {}

private :
  std::string value_;
};

#endif
