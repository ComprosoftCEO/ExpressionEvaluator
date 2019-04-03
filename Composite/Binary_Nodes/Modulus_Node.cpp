// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Modulus_Node.h"


//
// Constructor
//
Modulus_Node::Modulus_Node(Expr_Node* left_expr, Expr_Node* right_expr):
  Binary_Node(2, left_expr, right_expr) {}



//
// Modulus the two numbers
//
int Modulus_Node::do_operation(int left, int right) {
	return left % right;
}
