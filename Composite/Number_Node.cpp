// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Number_Node.h"
#include <Expr_Node_Visitor.h>



//
// Constructor
//
Number_Node::Number_Node(int value):
  value_(value) {}



//
// Evaluate
//
int Number_Node::evaluate() {
	return this->value_;
}


//
// Accept the visitor
//
void Number_Node::accept(Expr_Node_Visitor& v) {
	v.visit_number_node(*this);
}
