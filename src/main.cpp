#include "CodeGenContext.hpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/foreach.hpp>
#include <boost/program_options.hpp>

#define foreach BOOST_FOREACH

namespace po = boost::program_options;

using std::cout;
using std::string;
using std::ofstream;

extern "C" {
  extern FILE *yyin;
  int yylex(void);
  int yyparse(void);
}

// 儲存 AST 的根節點。見 src/parser.ypp。 
extern Node *root;

void print_vm(po::options_description &opts,
  po::variables_map &vm);

int main(int argc, char *argv[])
{
  bool dump;
  bool jit;
  string ifname;
  string ofname;
  ofstream ofile;

  // 處理命令列參數
  po::options_description opts("選項");
  opts.add_options()
    ("help,h", "顯示幫助訊息")

    ("input-file,i", po::value<string>(&ifname), "指定輸入檔案")

    ("dump,d", po::value<bool>(&dump)->default_value(false)
      ->implicit_value(true), "輸出 LLVM 組語")

    ("jit,j", po::value<bool>(&jit)->default_value(false)
      ->implicit_value(true), "JIT LLVM Module")
  ;

  po::positional_options_description pod;
  pod.add("input-file", 1);
  auto pr = po::command_line_parser(argc, argv).
            options(opts).
            positional(pod).
            allow_unregistered().
            run();

  std::vector<string> unkown_opts =
    po::collect_unrecognized(pr.options, po::exclude_positional);

  foreach(std::string str, unkown_opts)
  {  std::cout << "Unkown options: " << str << std::endl;  }

  po::variables_map vm;
  po::store(pr, vm);
  po::notify(vm);

  print_vm(opts, vm);
}

void print_vm(po::options_description &opts,
  po::variables_map &vm)
{
  if (vm.size() == 0)
    std::cout << opts << std::endl;

  if (vm.count("help"))
    std::cout << opts << std::endl;

  if (vm.count("input-file"))
  {
    // yyin 預設為 stdin。可以指定 yyin 不同的 FILE* 改變輸入裝置。
    // 因無法由 C++ fstream 取得 FILE*，故改用 C fopen 函數。
    yyin = fopen(vm["input-file"].as<string>().c_str(), "r");

    // 呼叫 Bison 產生的 yyparse 函式。
    yyparse();

    CodeGenContext context;

    // 呼叫個別節點的 CodeGen 函式。
    context.CodeGen(*root);

    if (vm["dump"].as<bool>())
      context.Dump();
    else if (vm["jit"].as<bool>())
      context.Run();
    else
      context.WriteBitCode();
  }
}
