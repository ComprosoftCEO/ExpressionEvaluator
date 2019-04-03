// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Divide_Node.h"


//
// Constructor
//
Divide_Node::Divide_Node(Expr_Node* left_expr, Expr_Node* right_expr):
  Binary_Node(2, left_expr, right_expr) {}



//
// Divide the two numbers
//
int Divide_Node::do_operation(int left, int right) {
	if (right == 0) {
		throw Divide_Node::divide_by_zero_exception();
	}
	return left / right;
}
