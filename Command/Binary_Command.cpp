// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Binary_Command.h"


//
// Constructor
//
Binary_Command::Binary_Command(Stack<int>& stack, int precedence):
  Command(stack, precedence) {}



//
// Run the stored binary function
//
void Binary_Command::execute(void) {

	//Pop 2 numbers off the stack
	int first, second;
	second = this->stack.pop();
	first = this->stack.pop();

	//Run the stored binary method
	int result = this->do_operation(first, second);

	//Push the result back onto the stack
	this->stack.push(result);
}
