// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Calculator.h"

#include <cctype> /* For isalpha() and isalnum() */
#include <functional>
#include <map>
#include <sstream>

//
// Lookup array for all builder token actions
//
static const std::map<std::string, std::function<void(Expr_Builder&)>> ALL_ACTIONS = {
    {"+", [](Expr_Builder& builder) { builder.build_add_operator(); }},
    {"-", [](Expr_Builder& builder) { builder.build_subtract_operator(); }},
    {"*", [](Expr_Builder& builder) { builder.build_multiply_operator(); }},
    {"/", [](Expr_Builder& builder) { builder.build_divide_operator(); }},
    {"%", [](Expr_Builder& builder) { builder.build_modulus_operator(); }},
    {"(", [](Expr_Builder& builder) { builder.build_left_parenthesis(); }},
    {")", [](Expr_Builder& builder) { builder.build_right_parenthesis(); }},
};

//
// Constructor
//
Calculator::Calculator(Expr_Builder& builder): builder(builder) {}

//
// Release any currently stored expressions
//
void Calculator::release_expressions() {
  this->builder.release_all_expressions();
}

//
// Get the builder
//
Expr_Builder& Calculator::get_builder() {
  return this->builder;
}

//
// Parse an infix expression and convert to an abstract data type
//
Math_Expr* Calculator::parse_infix_expression(const std::string& infix_expr) {

  // Start a new expression
  this->builder.release_expression_state();
  this->builder.start_new_expression();

  // Read and process all tokens
  std::stringstream ss(infix_expr);
  std::string token;
  while (ss >> token) { this->process_single_token(token); }

  // End the expression
  this->builder.end_expression();
  return this->builder.get_expression();
}

//
// Process a single token
//
void Calculator::process_single_token(const std::string& token) {

  // Build a number
  if (is_number(token)) {
    this->builder.build_number(std::stoi(token));
    return;
  }

  // Build a variable
  if (is_variable(token)) {
    this->builder.build_variable(token);
    return;
  }

  // Okay, search for the action to run using the lookup map
  auto action = ALL_ACTIONS.find(token);
  if (action != ALL_ACTIONS.end()) {
    action->second(this->builder);
    return;
  }

  // Unknown symbol! Problem!
  throw Expr_Builder::invalid_operator_exception(token);
}

//
// Test if the string is a number
//
bool Calculator::is_number(const std::string& token) {
  // We can use the default C++ number conversion to test if it
  //  is a valid number or not
  char* p;
  strtol(token.c_str(), &p, 10);
  return *p == 0;
}

//
// Test if the string is a variable
//
bool Calculator::is_variable(const std::string& token) {

  // Empty string is NOT a valid variable
  if (token.length() == 0) { return false; }

  // Every character must be an upper or lowercase number
  for (size_t i = 0; i < token.length(); ++i) {
    char c = token[i];
    if (!isalpha(c)) { return false; }
  }

  return true;
}
