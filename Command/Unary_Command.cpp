// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Unary_Command.h"


//
// Constructor
//
Unary_Command::Unary_Command(int precedence):
  Operator_Command(precedence) {}


//
// Run the stored unary function
//
void Unary_Command::execute(Stack<int>& stack) {

	//Pop 1 number off the stack
	int val = stack.pop();

	//Run the unary operation
	val = this->do_operation(val);

	//Push the result back onto the stack
	stack.push(val);
}
