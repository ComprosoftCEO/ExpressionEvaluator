// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Multiply_Node.h"
#include <Expr_Node_Visitor.h>


//
// Constructor
//
Multiply_Node::Multiply_Node(Expr_Node* left_expr, Expr_Node* right_expr):
  Binary_Node(2, left_expr, right_expr) {}



//
// Multiply the two numbers
//
int Multiply_Node::do_operation(int left, int right) {
	return left * right;
}


//
// Accept the visitor
//
void Multiply_Node::accept(Expr_Node_Visitor& v) {
	v.visit_multiply_node(*this);
}

