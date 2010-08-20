#include "CodeGenContext.hpp"

extern "C" {
  int yyparse(void);
}

// 儲存 AST 的根節點。見 src/parser.ypp。 
extern Node *root;

int main(int argc, char** argv)
{

  // 呼叫 Bison 產生的 yyparser 函式。
  yyparse();

  CodeGenContext context;

  // 呼叫個別節點的 CodeGen 函式。
  context.CodeGen(*root);
  context.Print();
}
