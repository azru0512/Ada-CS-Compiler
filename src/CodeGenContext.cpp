#include "CodeGenContext.hpp"
#include "AST/Node.hpp"
#include "Type/Type.hpp"
#include "Type/IntType.hpp"
#include "Type/FloatType.hpp"
#include "Type/BooleanType.hpp"
#include "llvm/DerivedTypes.h"
#include "llvm/GlobalValue.h"
#include "llvm/LLVMContext.h"
#include "llvm/Module.h"
#include "llvm/PassManager.h"
#include "llvm/Type.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetSelect.h"
#include <string>
#include <vector>
#include <iostream>

using llvm::BasicBlock;
using llvm::FunctionType;
using llvm::GlobalValue;
using llvm::PassManager;
using llvm::outs;
using std::string;
using std::cerr;

//class BasicBlock;

CodeGenContext::CodeGenContext(const std::string &name)
  : module_(new llvm::Module(name, llvm::getGlobalContext())),
    builder_(module_->getContext())
{
  // 建立 main 函式。其 prototype 為 void (void)
  FunctionType *ftype =
    FunctionType::get(llvm::Type::getInt64Ty(module_->getContext()), false);

  /// By passing a module as the last parameter to the Function constructor,
  /// it automatically gets appended to the Module.
  main_func_ =
    llvm::Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module_);

  /// Add a basic block to the function... again, it automatically inserts
  /// because of the last argument.
  BasicBlock *bblock =
    BasicBlock::Create(module_->getContext(), "entry", main_func_);

  /// IRBuilder is set up.
  builder_.SetInsertPoint(bblock);
}

const llvm::Type *CodeGenContext::TypeOf(const Type &type)
{
  if (typeid(type) == typeid(IntType))
    return llvm::Type::getInt64Ty(llvm::getGlobalContext());
  else if (typeid(type) == typeid(FloatType))
    return llvm::Type::getDoubleTy(llvm::getGlobalContext());
  else if (typeid(type) == typeid(BooleanType))
    return llvm::Type::getInt1Ty(llvm::getGlobalContext());
  else // Not LLVM support data type
    return llvm::Type::getVoidTy(llvm::getGlobalContext());
}

llvm::Value *CodeGenContext::InitValue(const Type &type)
{
  return llvm::Constant::getNullValue(TypeOf(type));
}

llvm::AllocaInst *CodeGenContext::CreateEntryBlockAlloca(llvm::Function *func,
  const Type &type, const std::string &name)
{
  llvm::IRBuilder<> tmp(&func->getEntryBlock(), func->getEntryBlock().begin());

  if (typeid(type) == typeid(IntType))
    return tmp.CreateAlloca(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, name.c_str());
  else if (typeid(type) == typeid(FloatType))
    return tmp.CreateAlloca(llvm::Type::getDoubleTy(llvm::getGlobalContext()), 0, name.c_str());
  else if (typeid(type) == typeid(BooleanType))
    return tmp.CreateAlloca(llvm::Type::getInt64Ty(llvm::getGlobalContext()), 0, name.c_str());
  else
    return tmp.CreateAlloca(llvm::Type::getVoidTy(llvm::getGlobalContext()), 0, name.c_str());
}

void CodeGenContext::WriteBitCode() const
{
  llvm::WriteBitcodeToFile(module_, llvm::outs());
}

void CodeGenContext::Run() const
{
  if (Verify())
  {
    llvm::InitializeNativeTarget();
    llvm::ExecutionEngine *ee = llvm::EngineBuilder(module_).create();
    std::vector<llvm::GenericValue> noargs;
    llvm::GenericValue gv = ee->runFunction(main_func_, noargs);
    llvm::outs() << "Result: " << gv.IntVal << "\n";
    llvm::llvm_shutdown();
  }
  else
  {
    std::cerr << "Module is wrong!\n";
  }
}

bool CodeGenContext::Verify() const
{
  return !llvm::verifyModule(*(this->module_), llvm::PrintMessageAction); 
}
