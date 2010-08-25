#ifndef _BLOCKSTAT_HPP_
#define _BLOCKSTAT_HPP_


#include "AST/Statement.hpp"
#include <boost/ptr_container/ptr_vector.hpp>

// 無用
class BlockStat : public Statement
{
public :
  void AddStatement(Statement *stat) { stat_list_.push_back(stat); }

priavte:
  boot::ptr_vector<Statement> stat_list_;
};

#endif
