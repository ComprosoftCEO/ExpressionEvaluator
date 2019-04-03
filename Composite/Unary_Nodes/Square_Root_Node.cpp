// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Square_Root_Node.h"
#include <cmath>		/* For sqrt() */


//
// Constructor
//
Square_Root_Node::Square_Root_Node(Expr_Node* child_expr):
  Unary_Node(0, child_expr) {}




//
// Take the square root of the input
//
int Square_Root_Node::do_operation(int input) {
	if (input < 0) {
		throw Square_Root_Node::negative_square_root_exception();
	}
	return sqrt(input);
}
