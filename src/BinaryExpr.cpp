#include "AST/BinaryExpr.hpp"
#include "AST/TokenNode.hpp"
#include "parser.h"
#include <iostream>

llvm::Value *BinaryExpr::CodeGen(llvm::IRBuilder<> &builder)
{
  llvm::Value *lval = lhs_->CodeGen(builder);
  llvm::Value *rval = rhs_->CodeGen(builder);

  if ((lval == 0) || (rval == 0))
    return 0;

  switch (boost::dynamic_pointer_cast<TokenNode>(op_)->token())
  {
    case PLUS:
      return builder.CreateAdd(lval, rval, "addtmp");
    case MINUS:
      return builder.CreateSub(lval, rval, "subtmp");
    case STAR:
      return builder.CreateMul(lval, rval, "multmp");
    case SLASH:
      return builder.CreateSDiv(lval, rval, "divtmp");
    case RW_MOD:
      return builder.CreateSRem(lval, rval, "modtmp");
    default:
      std::cerr << "No support operator\n";
  }
}
