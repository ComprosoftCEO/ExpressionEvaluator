// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Divide_Command.h"


//
// Constructor
//
Divide_Command::Divide_Command(Stack<int>& stack):
  Binary_Command(stack) {}



//
// Divide two numbers
//
int Divide_Command::do_operation(int left, int right) {
	return left / right;
}
