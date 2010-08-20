#include "SemanticAction.hpp"
#include "SymbolTable.hpp"
#include "AST/BinaryExpr.hpp"
#include "AST/IdNode.hpp"
#include "AST/TokenNode.hpp"
#include "AST/UnaryExpr.hpp"
#include "AST/IntegerExpr.hpp"
#include "AST/FloatExpr.hpp"
#include "AST/StringExpr.hpp"
#include "AST/VarNameExpr.hpp"
#include "AST/ObjDeclStat.hpp"
#include "AST/AssignStat.hpp"
#include "AST/list.hpp"
#include "Attribute/Keyword.hpp"
#include "Attribute/Variable.hpp"
#include "Attribute/TypeName.hpp"
#include "Type/BooleanType.hpp"
#include "Type/FloatType.hpp"
#include "Type/IntType.hpp"
#include "parser.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

extern Enviroment env;
extern IdList id_list;

void start()
{
#ifdef SYMTBL
  std::cout << "entering a global scope...\n";
#endif

  SymbolTable sym_tbl;

  for (size_t i = 0; i < NUM_KEYWORDS; ++i)
    sym_tbl.insert(SymbolTable::value_type(KW[i], new Keyword(RW_ABS + i)));

  sym_tbl.insert(SymbolTable::value_type("boolean", new TypeName(new BooleanType())));
  sym_tbl.insert(SymbolTable::value_type("float", new TypeName(new FloatType())));
  sym_tbl.insert(SymbolTable::value_type("integer", new TypeName(new IntType())));

  env.push_front(sym_tbl);
}

void finish()
{
#ifdef SYMTBL
  std::cout << "existing a global scope...\n";
  std::cout << env.front();
#endif

  env.pop_front();

#ifdef SYMTBL
  std::cout << "parseing is complete!\n";
#endif
}

/*
bool context_check(const string &name)
{
  if (lookup(name))
    return false;
  else
    return true;
}
*/

IdNode *process_id(const string &name)
{
  return new IdNode(name);
}

void start_id_list(Node *node)
{
  if (IdNode *id = dynamic_cast<IdNode*>(node))
    id_list.push_back(id->name());
}

void next_id(Node *node)
{
  if (IdNode *id = dynamic_cast<IdNode*>(node))
    id_list.push_back(id->name());
}

Statement *var_decl(Node *node)
{
  if (TypeNameExpr *name = dynamic_cast<TypeNameExpr*>(node))
  {
    IdEntryList id_entry_list;

    foreach(std::string id, id_list)
    {
      if (auto id_entry = Enter(id))
      {
        id_entry->second = new Variable(name->type(), 0);
        id_entry_list[id_entry->first] = id_entry->second;
      }
    }

    id_list.clear();

    return new ObjDeclStat(id_entry_list, name->type());
  }
}

/*
void type_decl(SemanticRecord *id_record, SemanticRecord *type_ref_record)
{
	try
	{
		Id &id = dynamic_cast<Id &>(*id_record);
		TypeRef &type_ref = dynamic_cast<TypeRef &>(*type_ref_record);

		string name = id.name();
		IdEntry *id_entry = Enter(name);
		Type *type = type_ref.object_type();

		if (id_entry)
		{
			id_entry->second = new TypeName(type);
		}
		else // id already there, error
		{
			cerr << name << " declared before\n";
		}
	}
	catch (bad_cast &bc)
	{
		cerr << "bad_cast caught: " << bc.what() << endl;
	}
}
*/

TypeNameExpr *type_reference(Node *node)
{
  if (IdNode *id = dynamic_cast<IdNode*>(node))
  {
    if (auto id_entry = Lookup(id->name()))
    {
      if (TypeName *type = dynamic_cast<TypeName *>(id_entry->second))
        return new TypeNameExpr(type->type());
    }
  }
}

/*
void start_record()
{
	enter_scope();
	stack_of_record.push(new RecordDef(new RecordType, 0));
}

void field_del(SemanticRecord *id_list_record, SemanticRecord *type_ref_record)
{
	try
	{
		IdList &id_list = dynamic_cast<IdList &>(*id_list_record);
		TypeRef &type_ref = dynamic_cast<TypeRef &>(*type_ref_record);
		RecordDef &record_def = dynamic_cast<RecordDef &>(*stack_of_record.top());

    IdList::ListOfId list_of_id = id_list.id_list();
    RecordDef::AddressRange next_offset = record_def.next_offset();
    Type *type = type_ref.object_type();
    Type::AddressRange size = type->size();

    foreach(Id *id, list_of_id)
    {
      string name = id->name();
      IdEntry *id_entry = enter(name);

      if (id_entry)
      {
        id_entry->second = new Field(type, next_offset);
        record_def.set_next_offset(size);
      }
		}
	}
	catch (bad_cast &bc)
	{
		cerr << "bad_cast caught: " << bc.what() << endl;
	}
}

SemanticRecord *end_record()
{
	try
	{
		RecordDef &record_def = dynamic_cast<RecordDef &>(*stack_of_record.top());
		
		RecordType *type = record_def.this_type();
		type->set_size(record_def.next_offset());
		type->update_sym_tbl(env.front());
		exit_scope();

		return new TypeRef(type);
	}
	catch (bad_cast &bc)
	{
		cerr << "bad_cast caught: " << bc.what() << endl;
	}
}
*/

VarNameExpr *new_name(Node *node)
{
  if (IdNode *id = dynamic_cast<IdNode*>(node))
  {
    if (auto id_entry = Lookup(id->name()))
    {
      if (Variable *attr = dynamic_cast<Variable *>(id_entry->second))
        return new VarNameExpr(id->name(), attr);
    }
  }
}

//SemanticRecord *check_data_object(SemanticRecord *name)
//{
/*
	SemanticRecord::Kind kind = name->kind();

	if (kind == SemanticRecord::DATAOBJECT)
		return name;
	else
		return new Error();
*/
//}

Expression *process_literal(long val)
{
  return new IntegerExpr(val);
}

Expression *process_literal(double val)
{
  return new FloatExpr(val);
}

Expression *process_literal(string val)
{
  return new StringExpr(val);
}

Node *process_op(size_t token)
{
  return new TokenNode(token);
}

UnaryExpr *eval_unary(Node *op, Node *rhs)
{
  return new UnaryExpr(op, rhs);
}

BinaryExpr *eval_binary(Node *lhs, Node *op, Node *rhs)
{
  return new BinaryExpr(lhs, op, rhs);
}

Statement *assignment(Node *lhs, Node *rhs)
{

  return new AssignStat(lhs, rhs);
}

void enter_scope()
{
#ifdef SYMTBL
  std::cout << "entering a scope...\n";
#endif

  SymbolTable sym_tbl;
  env.push_front(sym_tbl);
}

void exit_scope()
{
#ifdef SYMTBL
  std::cout << "existing a scope...\n";
  std::cout << env.front();
#endif

  env.pop_front();
}
