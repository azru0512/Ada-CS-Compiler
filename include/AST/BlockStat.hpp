#ifndef _BLOCKSTAT_HPP_
#define _BLOCKSTAT_HPP_


#include "AST/Statement.hpp"
#include <vector>

class BlockStat : public Statement
{
public :
  void AddStatement(Statement *stat) { stat_list_.push_back(*stat); }

priavte:
  std::vector<Statement *> stat_list_;
};

#endif
