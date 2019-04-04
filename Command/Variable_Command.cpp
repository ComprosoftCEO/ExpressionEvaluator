// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Variable_Command.h"



//
// Constructor
//
Variable_Command::Variable_Command(const std::string& name, int default_value):
  name_(name),
  value_(default_value) {}



//
// Push the variable value onto the stack
//
void Variable_Command::execute(Stack<int>& stack) {
	stack.push(this->value_);
}
