// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Subtract_Command.h"

#include <Command_Visitor.h>

//
// Constructor
//
Subtract_Command::Subtract_Command(): Binary_Command(1) {}

//
// Subtract two numbers
//
int Subtract_Command::do_operation(int left, int right) {
  return left - right;
}

//
// Accept the visitor
//
void Subtract_Command::accept(Command_Visitor& v) {
  v.visit_subtract_command(*this);
}
