#ifndef _STRINGVALUE_HPP_
#define _STRINGVALUE_HPP_


#include "Value/Value.hpp"
#include <string>

class StringValue : public Value
{
public :
	explicit StringValue(const std::string &value) : value_(value) {}

	string value() const { return value_; }

private :
	std::string value_; 
};

#endif
