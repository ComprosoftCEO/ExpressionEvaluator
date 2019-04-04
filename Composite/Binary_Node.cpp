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
int Binary_Node::evaluate() {

	int left = this->left_expr_->evaluate();
	int right = this->right_expr_->evaluate();

	return this->do_operation(left, right);
}



//
// Load children from the stack
//
void Binary_Node::load_children_from_stack(Stack<Expr_Node*>& stack) {

	if (stack.size() < 2) {
		throw Stack<Expr_Node*>::empty_exception();
	}

	//Delete my existing children (does nothing if NULL)
	delete(this->left_expr_);
	delete(this->right_expr_);

	//Pop in reverse order
	this->right_expr_ = stack.pop();
	this->left_expr_ = stack.pop();
}
