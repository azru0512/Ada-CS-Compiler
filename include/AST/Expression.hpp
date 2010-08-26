#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_


#include "AST/Node.hpp"
#include "Type/Type.hpp"
#include <boost/smart_ptr/shared_ptr.hpp>

// 類別 Expression
//
// - 所有運算式節點的基底類別
class Expression : public Node
{
public :
  explicit Expression(Type *type = 0) : type_(type) {}

  Type *type() const { return type_.get(); }

protected :
  boost::shared_ptr<Type> type_;
};

#endif
