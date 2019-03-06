// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Multiply_Command.h"


//
// Constructor
//
Multiply_Command::Multiply_Command(Stack<int>& stack):
  Binary_Command(stack) {}



//
// Multiply two numbers
//
int Multiply_Command::do_operation(int left, int right) {
	return left * right;
}
