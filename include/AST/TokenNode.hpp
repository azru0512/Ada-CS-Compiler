#ifndef _TOKENNODE_HPP_
#define _TOKENNODE_HPP_


#include "AST/Node.hpp"

class TokenNode : public Node
{
public :
  explicit TokenNode(size_t token)
    : token_(token) {}

  size_t token() const { return token_; }

private :
  size_t token_;
};

#endif
