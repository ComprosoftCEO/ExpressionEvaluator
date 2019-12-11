// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Number_Command.h"

#include <Command_Visitor.h>

//
// Constructor
//
Number_Command::Number_Command(int number): number_(number) {}

//
// Push a number onto the stack
//
void Number_Command::execute(Stack<int>& stack) {
  stack.push(this->number_);
}

//
// Accept the visitor
//
void Number_Command::accept(Command_Visitor& v) {
  v.visit_number_command(*this);
}
