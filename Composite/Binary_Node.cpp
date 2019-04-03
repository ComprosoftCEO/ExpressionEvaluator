// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Binary_Node.h"


//
// Constructor
//
Binary_Node::Binary_Node(int precedence, Expr_Node* left_expr, Expr_Node* right_expr):
  Operator_Node(precedence),
  left_expr_(left_expr),
  right_expr_(right_expr) {}


//
// Destructor
//
Binary_Node::~Binary_Node() {

	// Recursively delete any subtrees
	delete(this->left_expr_);
	delete(this->right_expr_);
}



//
// Evaluate the binary expression
//
int Binary_Node::eval() {

	int left = this->left_expr_->eval();
	int right = this->right_expr_->eval();

	return this->do_operation(left, right);
}
