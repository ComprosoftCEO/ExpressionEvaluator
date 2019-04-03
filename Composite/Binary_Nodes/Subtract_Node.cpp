// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Subtract_Node.h"


//
// Constructor
//
Subtract_Node::Subtract_Node(Expr_Node* left_expr, Expr_Node* right_expr):
  Binary_Node(1, left_expr, right_expr) {}



//
// Subtract the two numbers
//
int Subtract_Node::do_operation(int left, int right) {
	return left - right;
}
