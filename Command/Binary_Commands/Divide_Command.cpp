// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Divide_Command.h"

#include <Command_Visitor.h>

//
// Constructor
//
Divide_Command::Divide_Command(): Binary_Command(2) {}

//
// Divide two numbers
//
int Divide_Command::do_operation(int left, int right) {
  if (right == 0) { throw Divide_Command::divide_by_zero_exception(); }
  return left / right;
}

//
// Accept the visitor
//
void Divide_Command::accept(Command_Visitor& v) {
  v.visit_divide_command(*this);
}
