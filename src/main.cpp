#include "CodeGenContext.hpp"
#include <cstdio>
#include <iostream>
#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

using std::cout;
using std::string;

extern "C" {
  extern FILE *yyin;
  int yylex(void);
  int yyparse(void);
}

// 儲存 AST 的根節點。見 src/parser.ypp。 
extern Node *root;

int main(int argc, char** argv)
{
  string ifname;

  // 處理命令列參數
  po::options_description desc("選項");
  desc.add_options()
    ("help,h", "顯示幫助訊息")
    ("file,f", po::value<string>(&ifname), "指定輸入檔案")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help"))
  {
    cout << desc << "\n";
    return 1;
  }

  if (vm.count("file"))
  {
    // yyin 預設為 stdin。可以指定 yyin 不同的 FILE* 改變輸入裝置。
    // 因無法由 C++ fstream 轉為 FILE*，故改用 C fopen 函數。
    yyin = fopen(ifname.c_str(), "r"); 
  }

  // 呼叫 Bison 產生的 yyparse 函式。
  yyparse();

  CodeGenContext context;

  // 呼叫個別節點的 CodeGen 函式。
  context.CodeGen(*root);
  context.Print();
}
