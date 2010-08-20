#include "CodeGenContext.hpp"
#include "AST/Node.hpp"
#include "Type/Type.hpp"
#include "Type/IntType.hpp"
#include "Type/FloatType.hpp"
#include "Type/BooleanType.hpp"
#include "llvm/DerivedTypes.h"
#include "llvm/LLVMContext.h"
#include "llvm/Module.h"
#include "llvm/Type.h"
#include "llvm/GlobalValue.h"
#include "llvm/Instructions.h"
#include "llvm/PassManager.h"
#include "llvm/ModuleProvider.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/Assembly/PrintModulePass.h"
#include "llvm/Support/raw_ostream.h"
#include <vector>
#include <iostream>

using llvm::FunctionType;
using llvm::GlobalValue;
using llvm::ReturnInst;
using llvm::PassManager;
using llvm::createPrintModulePass;
using llvm::outs;
using std::cerr;

class BasicBlock;

CodeGenContext::CodeGenContext(const std::string &name)
  : module_(new llvm::Module(name, llvm::getGlobalContext())),
    builder_(llvm::getGlobalContext())
{
  /// Create the main function: first create the type 'void ()'
  llvm::FunctionType *ftype = llvm::FunctionType::get(llvm::Type::getDoubleTy(llvm::getGlobalContext()), false);

  /// By passing a module as the last parameter to the Function constructor,
  /// it automatically gets appended to the Module.
  main_func_ = llvm::Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module_);

  /// Add a basic block to the function... again, it automatically inserts
  /// because of the last argument.
  llvm::BasicBlock *bblock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", main_func_);

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

llvm::AllocaInst *CodeGenContext::CreateEntryBlockAlloca(llvm::Function *func, const Type &type, const std::string &name)
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

llvm::GenericValue CodeGenContext::Run()
{
  llvm::ExecutionEngine *ee = llvm::EngineBuilder(module_).create();

  //std::vector<llvm::GenericValue> noargs;

  //void *fp = ee->getPointerToFunction(main_func_);
  //double (*func)() = (double (*)())(intptr_t)fp;
  //func();
  //std::cout << "Result: " << func();
  //llvm::GenericValue v = ee->runFunction(main_func_, noargs);
}
