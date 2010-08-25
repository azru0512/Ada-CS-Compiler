// 我們用 C++ map 容器實作符號表，其中存放識別字和其屬性。
// 以識別字的名字作為鍵值。

#ifndef _SYMBOLTABLE_HPP_
#define _SYMBOLTABLE_HPP_


#include "Attribute/Attribute.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <utility>

using std::ostream;
using std::string;
using std::stack;
using std::map;
using std::list;
using std::pair;

const size_t NUM_KEYWORDS = 44;

const string KW[NUM_KEYWORDS] = {
  "ABS", "ACCESS", "ALL", "AND", "ARRAY", "BEGIN",
  "BODY", "CASE", "CONSTANT", "DECLARE", "ELSE", "ELSIF",
  "END", "EXCEPTION", "EXIT", "FOR", "FUNCTION", "IF",
  "IN", "IS", "LOOP", "MOD", "NOT", "NULL",
  "OF", "OR", "OTHERS", "OUT", "PACKAGE", "PRAGMA",
  "PRIVATE", "PROCEDURE", "RAISE", "RANGE", "RECORD", "RETURN",
  "REVERSE", "SEPARATE", "SUBTYPE", "THEN", "TYPE", "USE", "WHEN",
  "WHILE" 
};

class Attribute;

// 供 ObjDelStat 使用的資料結構。
typedef pair<const string, Attribute> IdEntry;
typedef map<std::string, Attribute *> IdEntryList; 

// 號表中所存的項目。項目由識別字的名字和其屬性構成。
typedef pair<const string, Attribute *> SymTblEntry;

// 符號表，其中存放識別字的名字和其屬性。
typedef map<const string, Attribute *> SymbolTable;

// 我們以鏈節串列的方式存放不同 scope 的符號表。
// 越內層的符號表越在鏈節串列的前端。
typedef list<SymbolTable> Enviroment;

// 由內向外搜尋符號表，預設區分名字大小寫。
SymTblEntry *Lookup(const string &name, bool sensitive = true);

// 將識別字填入目前 scope 的符號表。
SymTblEntry *Enter(const string &name);

// 設定該識別字的屬性。
void SetAttribute(SymTblEntry *id_entry);

// 判斷該識別字是否為關鍵字。
bool IsKeyword(const string &name);

ostream& operator<<(ostream& os, const SymbolTable &sym_tbl);
ostream& operator<<(ostream& os, const Enviroment &env);

#endif
