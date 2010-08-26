#ifndef _NODE_HPP_
#define _NODE_HPP_


#include "llvm/Value.h"
#include "llvm/Support/IRBuilder.h"

// 抽象語法樹 (Abstract Syntax Tree, AST) 中的節點將以 C++ 類別表示。
//
// 類別 Node 為其它節點的抽象基底類別 (Abstract Base Class, ABC) 
class Node
{
public :
  // 每個節點將會實作自己的虛擬函式 CodeGen。此函式用來產生 LLVM IR。
  // 不能傳入 const llvm::IRBuilder<> &builder，其成員函式為 non-const。
  virtual llvm::Value *CodeGen(llvm::IRBuilder<> &builder) {}

  virtual ~Node() {}
};

#endif
