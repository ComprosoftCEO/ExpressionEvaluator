// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Postfix_Expr.h"

#include <Variable_Getter.h>
#include <Variable_Setter.h>

//
// Evaluate the expression
//
int Postfix_Expr::evaluate() {

  // Reset the state of the stack
  this->stack_.clear();

  // Iterate over the array of commands
  for (size_t i = 0; i < this->to_run_.size(); ++i) { this->to_run_[i]->execute(this->stack_); }

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

//
// Add a sub expression onto my expression
//
void Postfix_Expr::append_sub_expression(const Postfix_Expr& expr) {
  for (size_t i = 0; i < expr.to_run_.size(); ++i) { this->add_command(expr.to_run_[i]); }
}

//
// Get all variable values
//
std::map<std::string, int> Postfix_Expr::get_variable_values() {

  Variable_Getter getter;

  // Iterate over the array of commands
  for (size_t i = 0; i < this->to_run_.size(); ++i) { this->to_run_[i]->accept(getter); }

  return getter.get_variables();
}

//
// Set all variable values
//
void Postfix_Expr::set_variable_values(const std::map<std::string, int>& values) {

  Variable_Setter setter(values);

  // Iterate over the array of commands
  for (size_t i = 0; i < this->to_run_.size(); ++i) { this->to_run_[i]->accept(setter); }
}
