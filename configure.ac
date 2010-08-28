#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.62)
AC_INIT(adacs, 0.1, chenwj@cs.nctu.edu.tw)
AM_INIT_AUTOMAKE(adacs,0.1)
AC_CONFIG_SRCDIR([src/SymbolTable.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
LT_INIT

# Checks for programs.
AC_PROG_CXX([g++44])

# 檢查系統是否裝有 lex 或與其相容的套件
AM_PROG_LEX

# 檢查系統是否裝有 yacc 或與其相容的套件
AC_PROG_YACC

#AX_BOOST_BASE(1.33.1])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.

AC_OUTPUT(Makefile src/Makefile include/Type/Makefile include/Attribute/Makefile include/AST/Makefile)
