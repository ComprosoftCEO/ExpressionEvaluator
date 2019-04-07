// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Modulus_Node.h"
#include <Expr_Node_Visitor.h>


//
// Constructor
//
Modulus_Node::Modulus_Node(Expr_Node* left_expr, Expr_Node* right_expr):
  Binary_Node(2, left_expr, right_expr) {}



//
// Modulus the two numbers
//
int Modulus_Node::do_operation(int left, int right) {
	if (right == 0) {
		throw Modulus_Node::modulus_zero_exception();
	}
	return left % right;
}


//
// Accept the visitor
//
void Modulus_Node::accept(Expr_Node_Visitor& v) {
	v.visit_modulus_node(*this);
}
