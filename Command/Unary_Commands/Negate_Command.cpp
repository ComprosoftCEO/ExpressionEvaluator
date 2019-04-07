// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Negate_Command.h"
#include <Command_Visitor.h>


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



//
// Accept the visitor
//
void Negate_Command::accept(Command_Visitor& v) {
	v.visit_negate_command(*this);
}
