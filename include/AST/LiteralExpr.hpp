#ifndef _LITERAL_HPP_
#define _LITERAL_HPP_


#include "AST/Expression.hpp"

class Type;

// 類別 LiteralExpr
//
// - 所有型態 literal 的基底類別。
class LiteralExpr : public Expression
{
public :
  explicit LiteralExpr(Type *type) : Expression(type) {}

  virtual ~LiteralExpr() {}
};

#endif
