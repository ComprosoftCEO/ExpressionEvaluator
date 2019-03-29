// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Flyweight_Expr_Factory.h"



//
// Constructor
//
Flyweight_Expr_Factory::Flyweight_Expr_Factory(Stack<int>& stack):
  Abstract_Expr_Factory(stack),
  add_command(stack),
  subtract_command(stack),
  multiply_command(stack),
  divide_command(stack),
  modulus_command(stack)
{}



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

	//Iterate over std::map using the iterator
	for (auto it = this->number_commands.begin(); it != this->number_commands.end(); ++it) {
		delete(it->second);
	}
}



//
// Get the number command
//
Number_Command* Flyweight_Expr_Factory::construct_number_command(int number) {

	//See if the command already exists in the map
	auto found_number = this->number_commands.find(number);
	if (found_number != this->number_commands.end()) {
		return found_number->second;
	}


	//Construct the new command and add it to the map
	Number_Command* new_number = new Number_Command(this->stack, number);
	this->number_commands[number] = new_number;
	return new_number;
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

