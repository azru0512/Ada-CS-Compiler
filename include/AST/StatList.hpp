#ifndef _STATLIST_HPP_
#define _STATLIST_HPP_

#include "AST/Statement.hpp"
#include <boost/ptr_container/ptr_vector.hpp>
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
    foreach(Statement &stat, stat_list_)
    {
      stat.CodeGen(builder);
    }
  }

private :
  // 注意! 不要使用 C++ STL 容器儲存指標。
  // 請見 http://www.parashift.com/c++-faq-lite/containers.html#faq-34.6
  boost::ptr_vector<Statement> stat_list_;
};

#endif
