#ifndef _PACKAGE_HPP_
#define _PACKAGE_HPP_


#include "AST/Node.hpp"
//#include "AST/StatList.hpp"
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

class Package : public Node
{
public :
  Package(Node *decl, Node *body)
    : decl_(decl), body_(body) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder)
  {
    decl_->CodeGen(builder);
    body_->CodeGen(builder);
  }

private :
  Node *decl_;
  Node *body_;
};

#endif
