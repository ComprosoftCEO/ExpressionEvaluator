// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Square_Root_Command.h"
#include <Command_Visitor.h>
#include <cmath>		/* For sqrt() */


//
// Constructor
//
Square_Root_Command::Square_Root_Command():
  Unary_Command(0) {}



//
// Square Root operation
//
int Square_Root_Command::do_operation(int input) {
	if (input < 0) {
		throw Square_Root_Command::negative_square_root_exception();
	}
	return sqrt(input);
}



//
// Accept the visitor
//
void Square_Root_Command::accept(Command_Visitor& v) {
	v.visit_square_root_command(*this);
}
