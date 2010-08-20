#ifndef _NULLSTAT_HPP_
#define _NULLSTAT_HPP_


#include "AST/Statement.hpp"

/// Class NullStat
/// Represents a null statement, i.e. ";" 
class NullStat : public Statement
{
public :
  NullStat() {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder) {}
};

#endif
