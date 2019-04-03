// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Unary_Command.h"


//
// Constructor
//
Unary_Command::Unary_Command(Stack<int>& stack, int precedence):
  Operator_Command(stack, precedence) {}


//
// Run the stored unary function
//
void Unary_Command::execute(void) {

	//Pop 1 number off the stack
	int val = this->stack.pop();

	//Run the unary operation
	val = this->do_operation(val);

	//Push the result back onto the stack
	this->stack.push(val);
}
