#include "SymbolTable.hpp"
#include "Attribute/Keyword.hpp"
#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/algorithm/string/case_conv.hpp>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using boost::algorithm::to_upper;
using boost::algorithm::to_upper_copy;

#define foreach BOOST_FOREACH

extern Enviroment env;

SymTblEntry *Lookup(const string &name, bool sensitive)
{
  SymbolTable::iterator id_entry;
  string id = sensitive? name : to_upper_copy(name);

  foreach(SymbolTable curr_sym_tbl, env) 
  {
    if ((id_entry = curr_sym_tbl.find(id)) != curr_sym_tbl.end())
      return &(*id_entry);
  }

  return nullptr;
}

SymTblEntry *Enter(const string &name)
{
  auto curr_sym_tbl = env.begin();

  // 當一識別字(第一次)被填入符號表時，其屬性未知。
  auto ret = curr_sym_tbl->insert(SymbolTable::value_type(name, static_cast<Attribute *>(0))); 
  if (ret.second) // 寫入成功。
    return &*(ret.first);
  else // 寫入失敗。因為目前 scope 的符號表中已存在相同名字的識別字。
    return nullptr;
}

void SetAttribute(IdEntry *id_entry)
{}

bool IsKeyword(const string &name)
{
  // 關鍵字於初始時即被填入全域符號表。
  Enviroment::const_reverse_iterator outmost_sym_tbl = env.rbegin();
  SymbolTable::const_iterator id_entry;

  if ((id_entry = outmost_sym_tbl->find(to_upper_copy(name))) !=
       outmost_sym_tbl->end() && typeid(*id_entry->second) == typeid(Keyword))
    return true;
  else
    return false;
}

std::ostream& operator<<(std::ostream& os, const SymbolTable &sym_tbl)
{
  foreach(SymTblEntry id_entry, sym_tbl)
  {
    os << id_entry.first << " => ";
    if (id_entry.second)
      id_entry.second->print();
    os << endl;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const Enviroment &env)
{
  foreach(SymbolTable curr_sym_tbl, env)
    os << curr_sym_tbl << endl;

  return os;
}
