#ifndef _FLOATVALUE_HPP_
#define _FLOATVALUE_HPP_


#include "Value/Value.hpp"

class FloatValue : public Value
{
public :
  explicit FloatValue(double value) : value_(value) {}

  double value() const { return value_; }

private :
  double value_;
};

#endif
