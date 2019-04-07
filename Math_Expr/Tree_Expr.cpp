// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Tree_Expr.h"
#include <Expr_Evaluator.h>


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
