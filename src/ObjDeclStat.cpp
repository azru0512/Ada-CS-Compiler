#include "AST/ObjDeclStat.hpp"
#include "Attribute/Variable.hpp"
#include "CodeGenContext.hpp"
#include "llvm/Instructions.h"
#include "llvm/Type.h"
#include <boost/foreach.hpp>
#include <iostream>

#define foreach BOOST_FOREACH

llvm::Value *ObjDeclStat::CodeGen(llvm::IRBuilder<> &builder)
{
  // 注意! LLVM 模組內含函數，函數內含基本塊。LLVM IRBuilder
  // 即是針對一個基本塊產出 LLVM 組語。
  llvm::Function *func = builder.GetInsertBlock()->getParent();
  llvm::Value *ret;

  foreach(IdEntryList::value_type id_entry, id_entry_list_)
  {
    llvm::AllocaInst *alloca =
      CodeGenContext::CreateEntryBlockAlloca(func, *type_, id_entry.first);
    
    dynamic_cast<Variable *>(id_entry.second)->set_value(alloca);

    llvm::Value *init = CodeGenContext::InitValue(*type_);

    ret = builder.CreateStore(init, alloca);
  }

  return ret;
}
