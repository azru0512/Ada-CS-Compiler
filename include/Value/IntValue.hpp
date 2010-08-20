#ifndef _INTVALUE_HPP_
#define _INTVALUE_HPP_


#include "Value/Value.hpp"

class IntValue : public Value
{
public :
  explicit IntValue(long value) :value_(value) {}

  long value() const { return value_; }

private :
  long value_;
};

#endif
