// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Tree_Expr.h"
#include <Expr_Evaluator.h>
#include <Variable_Getter.h>
#include <Variable_Setter.h>


//
// Constructor
//
Tree_Expr::Tree_Expr(Expr_Node* root):
  root_(root) {}



//
// Destructor
//
Tree_Expr::~Tree_Expr() {
	delete(this->root_);
}



//
// Evaluate the expression
//
int Tree_Expr::evaluate() {

	Expr_Evaluator eval;
	this->root_->accept(eval);
	return eval.get_result();
}



//
// Get all variable values
//
std::map<std::string, int> Tree_Expr::get_variable_values() {
	Variable_Getter getter;
	this->root_->accept(getter);
	return getter.get_variables();
}



//
// Set all variable values
//
void Tree_Expr::set_variable_values(const std::map<std::string, int>& values) {
	Variable_Setter setter(values);
	this->root_->accept(setter);
}
