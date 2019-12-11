// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Modulus_Command.h"

#include <Command_Visitor.h>

//
// Constructor
//
Modulus_Command::Modulus_Command(): Binary_Command(2) {}

//
// Left modulus right
//
int Modulus_Command::do_operation(int left, int right) {
  if (right == 0) { throw Modulus_Command::modulus_zero_exception(); }
  return left % right;
}

//
// Accept the visitor
//
void Modulus_Command::accept(Command_Visitor& v) {
  v.visit_modulus_command(*this);
}
