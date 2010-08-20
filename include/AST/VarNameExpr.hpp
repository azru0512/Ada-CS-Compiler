#ifndef _VARNAMEEXPR_HPP_
#define _VARNAMEEXPR_HPP_


#include "AST/Expression.hpp"
#include "Attribute/Variable.hpp"

/**
 * Class VarNameExpr
 * - 代表 variable reference。
 *
 * 注意! 在 AssignStat 的 CodeGen 中有兩個地方會用到 VarNameExpr
 * 所代表的 variable。
 *
 * 舉例: a := b + 1;
 *
 * 1. 當 variable 為 lhs 時，傳回 attribute 中的 llvm::Value*。 
 *
 * 2. 當 variable 為 rhs 時，呼叫 CodeGen。 
 */
class VarNameExpr : public Expression
{
public :
  VarNameExpr(const std::string &name, Variable *attr = 0)
    : name_(name), attr_(attr) {}

  /**
   * @param builder
   *
   * CodeGenContext::CodeGen() 中呼叫 AST node 的 CodeGen 時所傳入。
   * AST node 的 CodeGen 可利用此參數產生 LLVM IR。
   *
   * @return
   *
   * 傳回 llvm::Value* 供上層 AST node 的 CodeGen 使用。
   *
   */
  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    return builder.CreateLoad(attr_->value(), name_.c_str());
  }

  std::string name() const { return name_; }
  Variable *attr() const { return attr_; }

private :
  std::string name_;
  Variable *attr_;
};

#endif
