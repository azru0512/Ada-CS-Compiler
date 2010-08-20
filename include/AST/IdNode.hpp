#ifndef _IDNODE_HPP_
#define _IDNODE_HPP_


#include "AST/Node.hpp"
#include <string>

class IdNode : public Node
{
public :
  explicit IdNode(const std::string &name) : name_(name) {}

  std::string name() const { return name_; }

private :
  std::string name_;
};

#endif
