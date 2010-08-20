#include "AST/UnaryExpr.hpp"
#include "AST/TokenNode.hpp"
#include "parser.h"

llvm::Value *UnaryExpr::CodeGen(llvm::IRBuilder<> &builder)
{
  llvm::Value *value = expr_->CodeGen(builder);

  switch (dynamic_cast<TokenNode*>(op_)->token())
  {
    case PLUS:
      return value;
    case MINUS:
      return builder.CreateNeg(value);
  }
}
