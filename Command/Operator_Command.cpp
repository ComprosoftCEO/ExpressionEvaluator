// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment

#include "Operator_Command.h"



//
// Constructor
//
Operator_Command::Operator_Command(Stack<int>& stack, int precedence):
  Command(stack),
  precedence_(precedence) {}
