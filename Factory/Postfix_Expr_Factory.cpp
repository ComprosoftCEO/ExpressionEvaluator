// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Postfix_Expr_Factory.h"

//
// Destructor
//
Postfix_Expr_Factory::~Postfix_Expr_Factory() {
  this->release_products();
}

//
// Release dynamically allocated objects from memory
//
void Postfix_Expr_Factory::release_products() {
  while (!this->to_free.is_empty()) { delete (this->to_free.dequeue()); }
}

//
// Construct a new number
//
Number_Command* Postfix_Expr_Factory::construct_number_command(int number) {
  Number_Command* command = new Number_Command(number);
  this->to_free.enqueue(command);
  return command;
}

//
// Get the variable command
//
Variable_Command* Postfix_Expr_Factory::construct_variable_command(const std::string& name,
                                                                   int default_value) {
  Variable_Command* command = new Variable_Command(name, default_value);
  this->to_free.enqueue(command);
  return command;
}

//
// Create a new addition command
//
Add_Command* Postfix_Expr_Factory::construct_add_command() {
  Add_Command* command = new Add_Command();
  this->to_free.enqueue(command);
  return command;
}

//
// Create a new subtraction command
//
Subtract_Command* Postfix_Expr_Factory::construct_subtract_command() {
  Subtract_Command* command = new Subtract_Command();
  this->to_free.enqueue(command);
  return command;
}

//
// Create a new multiplication command
//
Multiply_Command* Postfix_Expr_Factory::construct_multiply_command() {
  Multiply_Command* command = new Multiply_Command();
  this->to_free.enqueue(command);
  return command;
}

//
// Create a new divide command
//
Divide_Command* Postfix_Expr_Factory::construct_divide_command() {
  Divide_Command* command = new Divide_Command();
  this->to_free.enqueue(command);
  return command;
}

//
// Create a new modulus command
//
Modulus_Command* Postfix_Expr_Factory::construct_modulus_command() {
  Modulus_Command* command = new Modulus_Command();
  this->to_free.enqueue(command);
  return command;
}
