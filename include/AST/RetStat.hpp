#ifndef _RETSTAT_HPP_
#define _RETSTAT_HPP_


#include "AST/Statement.hpp"

class RetStat : public Statement
{
public :
  RetStat(Node *expr = 0) : expr_(expr) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    if (expr_)
    {
      llvm::Value *value = expr_->CodeGen(builder);
      builder.CreateRet(value);
    }
    else
      builder.CreateRetVoid();
  }

private :
  Node *expr_;
};

#endif
