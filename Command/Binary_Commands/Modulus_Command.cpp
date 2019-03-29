// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Modulus_Command.h"


//
// Constructor
//
Modulus_Command::Modulus_Command(Stack<int>& stack):
  Binary_Command(stack) {}


//
// Left modulus right
//
int Modulus_Command::do_operation(int left, int right) {
	if (right == 0) {
		throw Modulus_Command::modulus_zero_exception();
	}
	return left % right;
}
