// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Variable_Setter.h"

//Expr_Node headers
#include <Number_Node.h>
#include <Variable_Node.h>
#include <Add_Node.h>
#include <Subtract_Node.h>
#include <Multiply_Node.h>
#include <Divide_Node.h>
#include <Modulus_Node.h>
#include <Negate_Node.h>
#include <Square_Root_Node.h>

//Command headers
#include <Number_Command.h>
#include <Variable_Command.h>
#include <Add_Command.h>
#include <Subtract_Command.h>
#include <Multiply_Command.h>
#include <Divide_Command.h>
#include <Modulus_Command.h>
#include <Negate_Command.h>
#include <Square_Root_Command.h>



//
// Constructor
//
Variable_Setter::Variable_Setter(const std::map<std::string, int>& lookup):
  lookup_(lookup) {}


//
// Visit methods that do nothing
//
void Variable_Setter::visit_number_command(Number_Command& command) {}
void Variable_Setter::visit_add_command(Add_Command& command) {}
void Variable_Setter::visit_subtract_command(Subtract_Command& command) {}
void Variable_Setter::visit_multiply_command(Multiply_Command& command) {}
void Variable_Setter::visit_divide_command(Divide_Command& command) {}
void Variable_Setter::visit_modulus_command(Modulus_Command& command) {}
void Variable_Setter::visit_negate_command(Negate_Command& command) {}
void Variable_Setter::visit_square_root_command(Square_Root_Command& command) {}
void Variable_Setter::visit_number_node(Number_Node& node) {}



//
// Visit a command variable
//
void Variable_Setter::visit_variable_command(Variable_Command& command) {
	auto search = this->lookup_.find(command.get_name());
	if (search != this->lookup_.end()) {
		command.set_value(search->second);
	}
}


//
// Visit a binary node
//
void Variable_Setter::visit_add_node(Add_Node& node) {
	this->do_binary_node(node);
}

void Variable_Setter::visit_subtract_node(Subtract_Node& node) {
	this->do_binary_node(node);
}

void Variable_Setter::visit_multiply_node(Multiply_Node& node) {
	this->do_binary_node(node);
}

void Variable_Setter::visit_divide_node(Divide_Node& node) {
	this->do_binary_node(node);
}

void Variable_Setter::visit_modulus_node(Modulus_Node& node) {
	this->do_binary_node(node);
}


//
// Visit a unary node
//
void Variable_Setter::visit_negate_node(Negate_Node& node) {
	this->do_unary_node(node);
}

void Variable_Setter::visit_square_root_node(Square_Root_Node& node) {
	this->do_unary_node(node);
}



//
// Visit a node variable
//
void Variable_Setter::visit_variable_node(Variable_Node& node) {
	auto search = this->lookup_.find(node.get_name());
	if (search != this->lookup_.end()) {
		node.set_value(search->second);
	}
}





//
// Recursively process a binary node
//
void Variable_Setter::do_binary_node(Binary_Node& node) {
	node.get_left_expression()->accept(*this);
	node.get_right_expression()->accept(*this);
}


//
// Recursively process a unary node
//
void Variable_Setter::do_unary_node(Unary_Node& node) {
	node.get_child_expression()->accept(*this);
}
