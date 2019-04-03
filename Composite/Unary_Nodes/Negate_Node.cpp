// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Negate_Node.h"


//
// Constructor
//
Negate_Node::Negate_Node(Expr_Node* child_expr):
  Unary_Node(0, child_expr) {}




//
// Multiply by -1
//
int Negate_Node::do_operation(int input) {
	return (-1) * input;
}
