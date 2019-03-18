// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Postfix_Expr_Factory.h"


//
// Constructor
//
Postfix_Expr_Factory::Postfix_Expr_Factory(Stack<int>& stack):
  Abstract_Expr_Factory(stack) {}



//
// Construct a new number
//
Number_Command* Postfix_Expr_Factory::construct_number_command(int number) {
	return new Number_Command(this->stack, number);
}


//
// Create a new addition command
//
Add_Command* Postfix_Expr_Factory::construct_add_command() {
	return new Add_Command(this->stack);
}


//
// Create a new subtraction command
//
Subtract_Command* Postfix_Expr_Factory::construct_subtract_command() {
	return new Subtract_Command(this->stack);
}


//
// Create a new multiplication command
//
Multiply_Command* Postfix_Expr_Factory::construct_multiply_command() {
	return new Multiply_Command(this->stack);
}


//
// Create a new divide command
//
Divide_Command* Postfix_Expr_Factory::construct_divide_command() {
	return new Divide_Command(this->stack);
}



//
// Create a new modulus command
//
Modulus_Command* Postfix_Expr_Factory::construct_modulus_command() {
	return new Modulus_Command(this->stack);
}
