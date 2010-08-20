
#ifndef _BINARYOP_HPP_
#define _BINARYOP_HPP_


#include "AST/Expression.hpp"

class BinaryExpr : public Expression
{
public :
  BinaryExpr(Node *lhs, Node *op, Node *rhs)
    : lhs_(lhs), op_(op), rhs_(rhs) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder);

private :
  Node *op_;
  Node *lhs_;
  Node *rhs_;
};

#endif
