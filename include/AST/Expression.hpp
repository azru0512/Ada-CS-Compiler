#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_


#include "AST/Node.hpp"
#include "Type/Type.hpp"

// 類別 Expression
//
// - 所有運算式節點的基底類別
class Expression : public Node
{
public :
  explicit Expression(Type *type = 0) : type_(type) {}

  Type *type() const { return type_; }

protected :
  Type *type_;
};

#endif
