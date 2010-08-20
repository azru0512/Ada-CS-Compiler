#ifndef _FLOATTYPE_HPP_
#define _FLOATTYPE_HPP_


#include "Type/Type.hpp"

class FloatType : public Type
{
public :
  void print() const { std::cout << "Float"; }
};

#endif
