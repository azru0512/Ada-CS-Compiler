#ifndef _INTTYPE_HPP_
#define _INTTYPE_HPP_


#include "Type/Type.hpp"
#include <iostream>

class IntType : public Type
{
public :
  void print() const { std::cout << "Integer"; }
};

#endif
