#ifndef _OBJDECLSTAT_HPP_
#define _OBJDECLSTAT_HPP_


#include "AST/DeclStat.hpp"
#include "Type/Type.hpp"
#include "SymbolTable.hpp"
#include <boost/smart_ptr/shared_ptr.hpp>

// 類別 ObjDeclStat
//
// 在剖析到以下程式碼時，會用到此類別:
//
// i, j : integer
//
class ObjDeclStat : public DeclStat
{
public :
  ObjDeclStat(const IdEntryList &id_entry_list, Type *type)
    : id_entry_list_(id_entry_list), type_(type) {}

  llvm::Value *CodeGen(llvm::IRBuilder<> &builder);

private :
  IdEntryList id_entry_list_;
  boost::shared_ptr<Type> type_;
};

#endif
