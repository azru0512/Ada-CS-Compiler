#include "AST/AssignStat.hpp"
#include "AST/VarNameExpr.hpp"
#include "SymbolTable.hpp"
#include "llvm/Value.h"
#include <iostream>

llvm::Value *AssignStat::CodeGen(llvm::IRBuilder<> &builder)
{
  llvm::Value *expr = expr_->CodeGen(builder);
  llvm::Value *var = dynamic_cast<VarNameExpr *>(var_)->attr()->value();

  builder.CreateStore(expr, var);
  return expr;
}
