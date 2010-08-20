#ifndef _ATTRIBUTE_HPP_
#define _ATTRIBUTE_HPP_

// 類別 Attribute 為一抽象基底類別 (abstract base class, ABC)。
//
// 每一個識別字 (identifier) 都帶有屬性。
class Attribute
{
public :
  virtual void print() const {}

  virtual ~Attribute() {}
};

#endif
