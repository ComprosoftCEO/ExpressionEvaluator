// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Flyweight_Expr_Factory.h"


//
// Destructor
//
Flyweight_Expr_Factory::~Flyweight_Expr_Factory() {
	this->release_products();
}



//
// Release any dynamically allocated products
//
void Flyweight_Expr_Factory::release_products() {

	// Use iterators to delete all allocated numbers
	for (auto it = this->number_commands.begin(); it != this->number_commands.end(); ++it) {
		delete(it->second);
	}
	this->number_commands.clear();


	// Use iterators to delete all allocated variables
	for (auto it = this->variable_commands.begin(); it != this->variable_commands.end(); ++it) {
		delete(it->second);
	}
	this->variable_commands.clear();
}



//
// Get the number command
//
Number_Command* Flyweight_Expr_Factory::construct_number_command(int number) {

	//See if the number already exists in the map
	auto search = this->number_commands.find(number);
	if (search != this->number_commands.end()) {
		return search->second;
	}

	//Insert a newly allocated number into the map
	Number_Command* command = new Number_Command(number);
	this->number_commands[number] = command;
	return command;
}


//
// Get the variable command
//
Variable_Command* Flyweight_Expr_Factory::construct_variable_command(const std::string& name, int default_value) {

	//See if the variable already exists in the map
	auto search = this->variable_commands.find(name);
	if (search != this->variable_commands.end()) {
		return search->second;
	}

	//Insert a newly allocated variable into the map
	Variable_Command* command = new Variable_Command(name, default_value);
	this->variable_commands[name] = command;
	return command;
}


//
// Get the static addition command
//
Add_Command* Flyweight_Expr_Factory::construct_add_command() {
	return &this->add_command;
}


//
// Get the static subtract command
//
Subtract_Command* Flyweight_Expr_Factory::construct_subtract_command() {
	return &this->subtract_command;
}



//
// Get the static multiply command
//
Multiply_Command* Flyweight_Expr_Factory::construct_multiply_command() {
	return &this->multiply_command;
}


//
// Get the static divide command
//
Divide_Command* Flyweight_Expr_Factory::construct_divide_command() {
	return &this->divide_command;
}


//
// Get the static modulus command
//
Modulus_Command* Flyweight_Expr_Factory::construct_modulus_command() {
	return &this->modulus_command;
}

