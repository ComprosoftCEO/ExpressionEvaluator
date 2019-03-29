// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Subtract_Command.h"


//
// Constructor
//
Subtract_Command::Subtract_Command(Stack<int>& stack):
  Binary_Command(stack) {}



//
// Subtract two numbers
//
int Subtract_Command::do_operation(int left, int right) {
	return left - right;
}
