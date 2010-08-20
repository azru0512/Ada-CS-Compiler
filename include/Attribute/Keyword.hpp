#ifndef _KEYWORD_HPP_
#define _KEYWORD_HPP_


#include "Attribute/Attribute.hpp"
#include <iostream>


// 類別 Keyword。
//
// 識別字若為關鍵字則帶有此屬性。
class Keyword : public Attribute
{
public :
  explicit Keyword(size_t kwv) : kwv_(kwv) {}

  size_t kwv() const { return kwv_; }

  void print() const { std::cout << "Keyword"; }

private :
  size_t kwv_;
};


#endif
