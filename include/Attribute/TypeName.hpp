#ifndef _TYPENAME_HPP_
#define _TYPENAME_HPP_


#include "Attribute/Attribute.hpp"
#include "Type/Type.hpp"

// 類別 TypeName
//
// 識別字若代表一型態則帶有此屬性。
class TypeName : public Attribute
{
public :
  TypeName(Type *type) : type_(type) {}

  Type *type() const { return type_; }

  void print() const { type_->print(); }


private :
  Type *type_;
};

#endif
