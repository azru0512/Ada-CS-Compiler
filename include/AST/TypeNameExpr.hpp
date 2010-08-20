#ifndef _TYPENAMEREF_HPP_
#define _TYPENAMEREF_HPP_


#include "AST/Expression.hpp"

class TypeNameExpr : public Expression
{
public :
  TypeNameExpr(Type *type) : Expression(type) {}
};

#endif
