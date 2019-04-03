// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Tree_Expr.h"



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
	return this->root_->evaluate();
}
