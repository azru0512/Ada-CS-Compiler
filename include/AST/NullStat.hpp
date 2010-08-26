#ifndef _NULLSTAT_HPP_
#define _NULLSTAT_HPP_


#include "AST/Statement.hpp"

// 類別 NullStat
// 
// 代表空陳述句 ";"。 
class NullStat : public Statement
{
public :
  NullStat() {}

  // IRBuilder 不產生 IR。
  llvm::Value *CodeGen(llvm::IRBuilder<> &builder) {}
};

#endif
