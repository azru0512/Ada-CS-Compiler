#ifndef _IFSTAT_HPP_
#define _IFSTAT_HPP_


#include "AST/Statement.hpp"
#include "AST/Expression.hpp"
#include "AST/StatList.hpp"

class IfStat : public Statement
{
public :
  IfStat(Expression *cond, StatList *then_stat, StatList *else_stat)
    : cond_(cond), then_stat_(then_stat), else_stat_(else_stat) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder);

private :
  Expression *cond_;
  StatList *then_stat_;
  StatList *else_stat_;  
};

#endif
