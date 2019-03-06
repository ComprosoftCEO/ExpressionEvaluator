// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Square_Root_Command.h"
#include <cmath>		/* For sqrt() */


//
// Constructor
//
Square_Root_Command::Square_Root_Command(Stack<int>& stack):
  Unary_Command(stack) {}



//
// Square Root operation
//
int Square_Root_Command::do_operation(int input) {
	return sqrt(input);
}
