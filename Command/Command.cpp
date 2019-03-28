// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Command.h"


//
// Initializing Constructor
//
Command::Command(Stack<int>& stack, int precedence):
  stack(stack),
  precedence(precedence) {}


//
// Destructor
//
Command::~Command() = default;



//
// Get the precedence
//
int Command::get_precedence() const {
	return this->precedence;
}
