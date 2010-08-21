INCLUDES = -I $(top_srcdir)/include

# http://www.gnu.org/software/hello/manual/automake/Yacc-and-Lex.html#Yacc-and-Lex
BUILT_SOURCES = parser.h

AM_YFLAGS = -d

bin_PROGRAMS = parser

parser_SOURCES = main.cpp parser.ypp scanner.lpp SymbolTable.cpp SemanticAction.cpp CodeGenContext.cpp ObjDeclStat.cpp BinaryExpr.cpp UnaryExpr.cpp AssignStat.cpp IfStat.cpp 

parser_LDADD = @LEXLIB@

AM_CXXFLAGS = -O3 -std=c++0x -Wl,--rpath,/usr/local/lib/gcc44

AM_CPPFLAGS = -I ${includedir}:$(top_srcdir)/include `llvm-config --cxxflags`

AM_LDFLAGS = `llvm-config --ldflags --libs all` -lboost_program_options
