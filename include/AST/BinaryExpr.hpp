
#ifndef _BINARYOP_HPP_
#define _BINARYOP_HPP_


#include "AST/Expression.hpp"
#include <boost/smart_ptr/shared_ptr.hpp>

class BinaryExpr : public Expression
{
public :
  BinaryExpr(Node *lhs, Node *op, Node *rhs)
    : lhs_(lhs), op_(op), rhs_(rhs) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder);

private :
  boost::shared_ptr<Node> op_;
  boost::shared_ptr<Node> lhs_;
  boost::shared_ptr<Node> rhs_;
};

#endif
