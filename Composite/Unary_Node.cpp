// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Unary_Node.h"

//
// Constructor
//
Unary_Node::Unary_Node(int precedence, Expr_Node* child_expr):
  Operator_Node(precedence), child_expr_(child_expr) {}

//
// Destructor
//
Unary_Node::~Unary_Node() {

  // Recursively delete the child expression tree
  delete (this->child_expr_);
}

//
// Evaluate the unary expression
//
int Unary_Node::evaluate() {
  int value = this->child_expr_->evaluate();
  return this->do_operation(value);
}

//
// Load children from the stack
//
void Unary_Node::load_children_from_stack(Stack<Expr_Node*>& stack) {

  Expr_Node* node = stack.pop(); // Might throw an exception

  // Delete the child and replace
  delete (this->child_expr_);
  this->child_expr_ = node;
}
