// 本標頭檔定義語意分析所會用到的函式。

#ifndef _SEMANTICACTION_HPP_
#define _SEMANTICACTION_HPP_


#include "AST/IdNode.hpp"
#include "AST/TypeNameExpr.hpp"
#include "AST/Statement.hpp"
#include <string>

class BinaryExpr;
class Expression;
class TokenNode;
class TypeNameExpr;
class UnaryExpr;
class VarNameExpr;

// 1. 初始全域符號表，並在其中填入關鍵字和原生型態。
// 2. 將全域符號表填入 Enviroment。
void start();

// 清空 Enviroment 中的符號表。
void finish();

bool context_check(std::string name); // see if variable is defined before used

// 抽象語法樹 (Abstract Syntax Tree, AST) 的葉節點。 
// 撰寫 Semantic Action 最開始的地方。
IdNode *process_id(const std::string &name);

// 將 id 名字填入 id_list。
void start_id_list(Node *node);

// 將 id 名字填入 id_list。
void next_id(Node *node);

// 宣告變數。
// id : type
Statement *var_decl(Node *node);

// Enter the identifier into current symbol table with attribute "TypeName".
// (p.330)
//void type_decl(const IdNode &id, SemanticRecord *type_ref);

// 判斷該識別字是否代表一型態。
TypeNameExpr *type_reference(Node *node);

//void start_record(); // p.336

//void field_del(SemanticRecord *id_list, SemanticRecord *type_ref); // p.337

//SemanticRecord *end_record();

// 判斷該識別字是否代表一變數。
VarNameExpr *new_name(Node *node);

//SemanticRecord *check_data_object(SemanticRecord *name);

Expression *process_literal(long val);

Expression *process_literal(double val);

Expression *process_literal(std::string val);

Node *process_op(size_t op);

UnaryExpr *eval_unary(Node *op, Node *rhs);

BinaryExpr *eval_binary(Node *lhs, Node *op, Node *rhs);

Statement *assignment(Node *lhs, Node *rhs);

//void select_unary_operator();

//void select_binary_operator();

//void get_temporary();

//void bi_no_code_needed();

//void un_no_code_needed();

void enter_scope();

void exit_scope();

//void global_simple_var();

//void local_simple_car();


#endif
