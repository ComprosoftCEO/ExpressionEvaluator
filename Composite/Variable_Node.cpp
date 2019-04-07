// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Variable_Node.h"
#include <Expr_Node_Visitor.h>


//
// Constructor
//
Variable_Node::Variable_Node(const std::string& name, int default_value):
  name_(name),
  value_(default_value) {}



//
// Push the variable value onto the stack
//
int Variable_Node::evaluate() {
	return this->value_;
}



//
// Accept the visitor
//
void Variable_Node::accept(Expr_Node_Visitor& v) {
	v.visit_variable_node(*this);
}
