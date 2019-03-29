// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Add_Command.h"


//
// Constructor
//
Add_Command::Add_Command(Stack<int>& stack):
  Binary_Command(stack) {}



//
// Add two numbers
//
int Add_Command::do_operation(int left, int right) {
	return left + right;
}
