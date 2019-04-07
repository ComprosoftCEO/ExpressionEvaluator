// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Variable_Getter.h"



//
// Visit methods that do nothing
//
void Variable_Getter::visit_number_command(Number_Command& command) {}
void Variable_Getter::visit_add_command(Add_Command& command) {}
void Variable_Getter::visit_subtract_command(Subtract_Command& command) {}
void Variable_Getter::visit_multiply_command(Multiply_Command& command) {}
void Variable_Getter::visit_divide_command(Divide_Command& command) {}
void Variable_Getter::visit_modulus_command(Modulus_Command& command) {}
void Variable_Getter::visit_negate_command(Negate_Command& command) {}
void Variable_Getter::visit_square_root_command(Square_Root_Command& command) {}
void Variable_Getter::visit_number_node(Number_Node& node) {}



//
// Visit a command variable
//
void Variable_Getter::visit_variable_command(Variable_Command& command) {
	this->variables_[command.get_name()] = command.get_value();
}


//
// Visit a binary node
//
void Variable_Getter::visit_add_node(Add_Node& node) {
	this->do_binary_node(node);
}

void Variable_Getter::visit_subtract_node(Subtract_Node& node) {
	this->do_binary_node(node);
}

void Variable_Getter::visit_multiply_node(Multiply_Node& node) {
	this->do_binary_node(node);
}

void Variable_Getter::visit_divide_node(Divide_Node& node) {
	this->do_binary_node(node);
}

void Variable_Getter::visit_modulus_node(Modulus_Node& node) {
	this->do_binary_node(node);
}


//
// Visit a unary node
//
void Variable_Getter::visit_negate_node(Negate_Node& node) {
	this->do_unary_node(node);
}

void Variable_Getter::visit_square_root_node(Square_Root_Node& node) {
	this->do_unary_node(node);
}



//
// Visit a node variable
//
void Variable_Getter::visit_variable_node(Variable_Node& node) {
	this->variables_[node.get_name()] = node.get_value();
}





//
// Recursively process a binary node
//
void Variable_Getter::do_binary_node(Binary_Node& node) {
	node.get_left_expression()->accept(*this);
	node.get_right_expression()->accept(*this);
}


//
// Recursively process a unary node
//
void Variable_Getter::do_unary_node(Unary_Node& node) {
	node.get_child_expression()->accept(*this);
}
