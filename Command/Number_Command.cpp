// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Number_Command.h"


//
// Constructor
//
Number_Command::Number_Command(Stack<int>& stack, int number):
  Command(stack),
  number_(number) {}



//
// Push a number onto the stack
//
void Number_Command::execute(void) {
	this->stack.push(this->number_);
}
