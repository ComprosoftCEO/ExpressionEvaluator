// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Binary_Command.h"


//
// Constructor
//
Binary_Command::Binary_Command(int precedence):
  Operator_Command(precedence) {}



//
// Run the stored binary function
//
void Binary_Command::execute(Stack<int>& stack) {

	//Pop 2 numbers off the stack
	int first, second;
	second = stack.pop();
	first = stack.pop();

	//Run the stored binary method
	int result = this->do_operation(first, second);

	//Push the result back onto the stack
	stack.push(result);
}
