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
	while(!this->to_free.is_empty()) {
		delete(this->to_free.dequeue());
	}
}



//
// Get the number command
//
Number_Command* Flyweight_Expr_Factory::construct_number_command(int number) {
	Number_Command* command = new Number_Command(number);
	this->to_free.enqueue(command);
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

