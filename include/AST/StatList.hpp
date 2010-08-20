#ifndef _STATLIST_HPP_
#define _STATLIST_HPP_

#include "AST/Statement.hpp"
#include <vector>
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

class StatList : public Statement
{
public :
  StatList() {}

  StatList(Node *node)
  {
    if (Statement *stat = dynamic_cast<Statement*>(node))
      stat_list_.push_back(stat);
  }

  void AddStatement(Node *node)
  {
    if (Statement *stat = dynamic_cast<Statement*>(node))  
      stat_list_.push_back(stat);
  }

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    foreach(Statement *stat, stat_list_)
    {
      stat->CodeGen(builder);
    }
  }

private :
  std::vector<Statement *> stat_list_;
};

#endif
