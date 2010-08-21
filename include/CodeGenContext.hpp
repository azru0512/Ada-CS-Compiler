#ifndef _CODEGENCONTEXT_HPP_
#define _CODEGENCONTEXT_HPP_


#include "AST/Node.hpp"
#include "llvm/LLVMContext.h"
#include "llvm/Module.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/Support/IRBuilder.h"
//#include "llvm/Support/raw_ostream.h"
#include <iostream>
#include <string>

class Type;
class AllocaInst;
class Function;

// 類別 CodeGenContext
//
// 產生 LLVM IR。注意! 此類別與 LLVM 關聯性極強。
class CodeGenContext
{
public :
  CodeGenContext(const std::string &name = "ada/cs");

  // 把 Ada/CS 中的型態對映至 LLVM 提供的型態
  static const llvm::Type *TypeOf(const Type &type);

  // 回傳相映於 Ada/CS 型態的 LLVM 型態初值
  static llvm::Value *InitValue(const Type &type);

  // 請見 http://llvm.org/docs/tutorial/LangImpl7.html
  // 為每個變數配置一塊記憶體空間。
  // LLVM::Function 是寫入 LLVM IR 的最上層結構。
  // 後兩個參數分別代表變數的型態和名字。
  static llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function *func,
    const Type &type, const std::string &name);

  // 呼叫各型別自己的虛擬函式
  void CodeGen(Node &root) { root.CodeGen(builder_); }

  // 將 Module 內容以 LLVM bitcode 的型式寫到輸出裝置 stdout。
  // 可用 llvm-dis 把 bicode 轉成 LLVM 組語。
  void WriteBitCode() const;

  //  將 Module 內容以 LLVM 組語的型式寫到輸出裝置 stderr。
  void Dump() const { module_->dump(); }

  void Run() const;
  
private :
  bool Verify() const;

  // LLVM IR 中最上層的結構為 LLVM::Module。
  // Module 裡面包含所有的函式和全域變數。
  llvm::Module *module_;

  // LLVM 提供的類別 IRBuilder 可用來產生 LLVM IR。
  llvm::IRBuilder<> builder_;

  // Module 裡面最上層的函式。
  // 函式包含 Basic Block。
  llvm::Function *main_func_;
};

#endif
