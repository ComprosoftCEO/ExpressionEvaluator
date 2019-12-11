// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Add_Command.h"

#include <Command_Visitor.h>

//
// Constructor
//
Add_Command::Add_Command(): Binary_Command(1) {}

//
// Add two numbers
//
int Add_Command::do_operation(int left, int right) {
  return left + right;
}

//
// Accept the visitor
//
void Add_Command::accept(Command_Visitor& v) {
  v.visit_add_command(*this);
}
