#ifndef _ASSIGNSTAT_HPP_
#define _ASSIGNSTAT_HPP_


#include "AST/Statement.hpp"

class AssignStat : public Statement
{
public :
  AssignStat(Node *var, Node *expr)
    : var_(var), expr_(expr) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder);

private :
  Node *var_;
  Node *expr_;
};

#endif
