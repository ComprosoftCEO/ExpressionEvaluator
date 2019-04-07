// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Add_Node.h"
#include <Expr_Node_Visitor.h>


//
// Constructor
//
Add_Node::Add_Node(Expr_Node* left_expr, Expr_Node* right_expr):
  Binary_Node(1, left_expr, right_expr) {}



//
// Add the two numbers
//
int Add_Node::do_operation(int left, int right) {
	return left + right;
}


//
// Accept the visitor
//
void Add_Node::accept(Expr_Node_Visitor& v) {
	v.visit_add_node(*this);
}
