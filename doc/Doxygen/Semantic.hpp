/** \page semantic 語意分析
 *
 * 語意分析重點在於建立抽象語法樹 (Abstract Syntax Tree, AST)，又稱語法樹 (Syntax Tree)。語法樹和在語法分析(即前一步驟)所建立的剖析樹不同的地方在於，語法樹省略了一些用來輔助語法分析的節點。例如: 出現在剖析樹中的括號，在建立語法樹時會省略。這是因為樹本身的結構即擁有括號所代表的意義。
 *
 * 我們使用 C++ 的類別代表語法樹中的節點。每個類別會各自儲存一些資訊，這些資訊將用來做為語意分析之用。
 *
 * 為了要產生中介碼，每個類別會實作一個虛擬函式 CodeGen。當語法樹建立完成後，我們會呼叫根節點的 CodeGen 函式。它再依序呼叫子節點的 CodeGen 函式。 
 *
 * 參考文件:
 * - <a href="http://hillside.net/plop/plop2003/Papers/Jones-ImplementingASTs.pdf">Abstract Syntax Tree Implementation Idioms</a>
 * - <a href="http://www.ansa.co.uk/ANSATech/95/Primary/155101.pdf">Abstract Syntax Tree Design</a>
 * - <a href="http://gnuu.org/2009/09/18/writing-your-own-toy-compiler/">Writing Your Own Toy Compiler Using Flex, Bison and LLVM</a>
 * - <a href="http://llvm.org/docs/tutorial/">LLVM Tutorial</a>
 *
 */ 
