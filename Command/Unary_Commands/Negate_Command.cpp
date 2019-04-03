// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Negate_Command.h"


//
// Constructor
//
Negate_Command::Negate_Command():
  Unary_Command(0) {}



//
// Multiply input by negative 1
//
int Negate_Command::do_operation(int input) {
	return -input;
}
