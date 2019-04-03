// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Postfix_Expr.h"


//
// Evaluate the expression
//
int Postfix_Expr::evaluate() {

	//Reset the state of the stack
	this->stack_.clear();

	//Iterate over the array of commands
	for (size_t i = 0; i < this->to_run_.size(); ++i) {
		this->to_run_[i]->execute();
	}

	return this->stack_.top();
}




//
// Add a command to the list of commands to execute
//
void Postfix_Expr::add_command(Command* command) {
	size_t cur_size = this->to_run_.size();
	size_t new_size = cur_size + 1;

	this->to_run_.resize(new_size);
	this->to_run_[cur_size] = command;
}
