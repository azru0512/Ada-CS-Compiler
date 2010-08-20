#ifndef _VARIABLE_HPP_
#define _VARIABLE_HPP_


#include "Attribute/Attribute.hpp"
#include "Type/Type.hpp"
#include "llvm/Value.h"

// 類別 Variable
//
// 識別字若為一變數則帶有此屬性。
class Variable : public Attribute
{
public :
  Variable(Type *type, llvm::AllocaInst *value)
    : type_(type), value_(value) {}

  Type *type() const { return type_; }
  llvm::Value *value() const { return value_; }

  void set_value(llvm::Value *value) { value_ = value; }

  void print() const { type_->print(); }

private :
  Type *type_;
  llvm::Value *value_;
};

#endif
