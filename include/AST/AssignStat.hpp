#ifndef _ASSIGNSTAT_HPP_
#define _ASSIGNSTAT_HPP_


#include "AST/Statement.hpp"
#include <boost/smart_ptr/shared_ptr.hpp>

class AssignStat : public Statement
{
public :
  AssignStat(Node *var, Node *expr)
    : var_(var), expr_(expr) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder);

private :
  boost::shared_ptr<Node> var_;
  boost::shared_ptr<Node> expr_;
};

#endif
