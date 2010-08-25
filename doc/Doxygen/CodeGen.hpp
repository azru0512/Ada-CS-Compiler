/** \page codegen 產生中介碼
 *
 * 注意! 強列建議參考 LLVM 源碼根目錄底下的 example 目錄裡的範例。
 *
 * 類別 CodeGenContext 用來作為耦合前端 (Flex + Bison) 與 LLVM 之間的元件。我們使用 LLVM 的 IRBuilder 來產生 LLVM 組語。
 *
 * LLVM 模塊 (module) 是 LLVM 所能見到的最上層結構。它可以是一個或多個翻譯單元組成，多個翻譯單元透過連結器形成一個 LLVM 模塊。LLVM 模塊內含函數 (function)，函數內含基本塊 (basic block)。LLVM IRBuilder 即是針對一個基本塊產出 LLVM 組語。
 *
 * llvm::Type 類別定義了 LLVM 的自定型別。另外，LLVM 指令中的運算元皆為 llvm::Value 類別或其衍生類別。llvm::Value 類別和其衍生類別均帶有 llvm::Type。
 *
 * LLVM 自 2.5 版之後支援多緒執行。llvm::LLVMContext 類別是用來確保多個 LLVM 實體之間不會互相干擾。
 *
 * LLVM 提供直譯器和即時編譯 (Just In Time, JIT)。即時編譯須目標平台支援。在啟動 JIT 之前，必須呼叫 llvm::LLVMInitializeAllTargets() 靜態函數以連結所有 LLVM 支援的平台。
 *
 * 參考文件:
 * - <a href="http://jvm.cs.nctu.edu.tw/~chenwj/slide/20081205_HowToUseJIT&MakeJITSupport_chenwj.pdf">How To Use JIT & Make JIT Support</a>
 * - <a href="http://gnuu.org/2009/09/18/writing-your-own-toy-compiler/">Writing Your Own Toy Compiler Using Flex, Bison and LLVM</a>
 * - <a href="http://www.gearleaf.com/blog/post/44">LLVM External Functions</a>
 * - <a href="http://llvm.org/docs/tutorial/">LLVM Tutorial</a>
 *
 */ 
