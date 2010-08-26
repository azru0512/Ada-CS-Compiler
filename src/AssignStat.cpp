#include "AST/AssignStat.hpp"
#include "AST/VarNameExpr.hpp"
#include "SymbolTable.hpp"
#include "llvm/Value.h"

llvm::Value *AssignStat::CodeGen(llvm::IRBuilder<> &builder)
{
  llvm::Value *expr = expr_->CodeGen(builder);
  llvm::Value *var =
    boost::dynamic_pointer_cast<VarNameExpr>(var_)->attr()->value();

  builder.CreateStore(expr, var);
  return expr;
}
