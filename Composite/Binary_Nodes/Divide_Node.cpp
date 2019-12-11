// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Divide_Node.h"

#include <Expr_Node_Visitor.h>

//
// Constructor
//
Divide_Node::Divide_Node(Expr_Node* left_expr, Expr_Node* right_expr):
  Binary_Node(2, left_expr, right_expr) {}

//
// Divide the two numbers
//
int Divide_Node::do_operation(int left, int right) {
  if (right == 0) { throw Divide_Node::divide_by_zero_exception(); }
  return left / right;
}

//
// Accept the visitor
//
void Divide_Node::accept(Expr_Node_Visitor& v) {
  v.visit_divide_node(*this);
}
