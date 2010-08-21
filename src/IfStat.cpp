#include "AST/IfStat.hpp"

llvm::Value *IfStat::CodeGen(llvm::IRBuilder<> &builder)
{
/*
  // 產生 condition expression 的指令。
  llvm::Value *condv = cond_->CodeGen(builder);

  if (!condv) return 0;

  // 藉 compare 將 condv 轉成 boolean (LLVM 中的型態 i1)。
  condv = builder.CreateICmpEQ(condv, llvm::ConstantFP::get(
    llvm::getGlobalContext(), llvm::APFloat(0.0)), "ifcond");
 
  // 取得目前欲插入指令的 basic block 所屬的 function 。
  llvm::Function *func = builder.GetInsertBlock()->getParent();
  
  // 分別替 then、else 和 ifcont 建立各自的 basic block 。並將 then
  // 的 basic block 放到 function 的尾端。
  llvm::BasicBlock *then_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(),
    "then", func);

  llvm::BasicBlock *else_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(),
    "else");

  llvm::BasicBlock *ifcont_bb = llvm::BasicBlock::Create(llvm::getGlobalContext(),
    "ifcont");

  // 產生 conditional branch 跳至 then 或是跳至 else 。
  builder.CreateCondBr(condv, then_bb, else_bb);

  // IRBuilder 將 emit code 至 then 所屬的 basic block 的尾端。
  builder.SetInsertPoint(then_bb);

  // 產生 else statement 的指令
  llvm::Value *thenv = then_stat_->CodeGen(builder);

  if (!thenv) return 0;

  // else 執行完畢後，無條件跳至 ifcont 所屬 basic block
  builder.CreateBr(ifcont_bb);

  // ifcont block 的 phi node 需要所有 predecessor enrty。
  //
  // 呼叫 else statement 的 CodeGen 時，可能會改變其欲 emit code 的
  // basic block。例如 else statement 中又有 if-then-else statement。
  // 
  // 因此這裡為 phi node 取得最新的 predecessor block。
  then_bb = builder.GetInsertBlock();

  // 之前僅將 then block 放至 function 的 block list。
  // 至此才將 else block 放至 function 的 block list 尾端。
  func->getBasicBlockList().push_back(else_bb);

  // IRBuilder 將 emit code 至 else 所屬的 basic block 的尾端。
  builder.SetInsertPoint(else_bb);
  
  // 底下與產生 else statement 指令的步驟相同。
  llvm::Value *elsev = else_stat_->CodeGen(builder);
  if (!elsev) return 0;
  
  builder.CreateBr(ifcont_bb);
  else_bb = builder.GetInsertBlock();

  // 將 ifcont block 放至 function 的 block list 尾端。
  func->getBasicBlockList().push_back(ifcont_bb);

  // IRBuilder 將 emit code 至 ifcont 所屬的 basic block 的尾端。
  builder.SetInsertPoint(ifcont_bb);

  // 建立 phi node。並為其建立 block/value pair。
  llvm::PHINode *phi = builder.CreatePHI(llvm::Type::getDoubleTy(llvm::getGlobalContext()),
    "iftmp");

  phi->addIncoming(thenv, then_bb);
  phi->addIncoming(elsev, else_bb);

  return phi;
*/
}
