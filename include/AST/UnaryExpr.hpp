#ifndef _UNARYEXPR_HPP_
#define _UNARYEXPR_HPP_


#include "AST/Expression.hpp"

class UnaryExpr : public Expression
{
public :
  UnaryExpr(Node *op, Node *expr)
    : op_(op), expr_(expr) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder);

private :
  Node *op_;
  Node *expr_;
};

#endif
