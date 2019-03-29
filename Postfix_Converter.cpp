// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Postfix_Converter.h"
#include <functional>
#include <map>
#include <sstream>

//
// Lookup array for all command objects (without using std::map)
//
struct LookupEntry {
  const char *symbol;
  int precedence;
  std::function<Command *(Abstract_Expr_Factory &)> construct_object;
};
static const LookupEntry ALL_OPERATIONS[] = {
    {"+", 1,
     [](Abstract_Expr_Factory &factory) -> Command * {
       return factory.construct_add_command();
     }},
    {"-", 1,
     [](Abstract_Expr_Factory &factory) -> Command * {
       return factory.construct_subtract_command();
     }},
    {"*", 2,
     [](Abstract_Expr_Factory &factory) -> Command * {
       return factory.construct_multiply_command();
     }},
    {"/", 2,
     [](Abstract_Expr_Factory &factory) -> Command * {
       return factory.construct_divide_command();
     }},
    {"%", 2, [](Abstract_Expr_Factory &factory) -> Command * {
       return factory.construct_modulus_command();
     }}};

/**
 * Search for the entry associated with a given operation symbol
 *
 * @param[in]		token		The operator to look for
 * @return			The associated entry
 * @retval			nullptr		The entry is not found
 */
static const LookupEntry *find_operation(const std::string &token) {
  for (size_t i = 0; i < (sizeof(ALL_OPERATIONS) / sizeof(ALL_OPERATIONS[0]));
       ++i) {
    if (token == ALL_OPERATIONS[i].symbol) {
      return ALL_OPERATIONS + i;
    }
  }
  return nullptr;
}

//
// Constructor
//
Postfix_Converter::Postfix_Converter(Abstract_Expr_Factory &factory)
    : factory(factory) {}

//
// Convert an expression to postfix
//
Queue<Command *>
Postfix_Converter::convert_to_postfix(const std::string &infix_expr) {

  // Reset the parser state
  this->expression.clear();
  this->last_token_number = false;

  // Read and process all tokens
  std::stringstream ss(infix_expr);
  std::string token;
  while (ss >> token) {
    this->process_single_token(token);
  }

  // Last token needs to be a number for the expression to be valid
  if (!this->last_token_number) {
    throw Postfix_Converter::invalid_infix_exception();
  }

  // Add any other elements from the stack
  this->pop_remaining_operators();

  return this->expression;
}

//
// Process a single token
//
void Postfix_Converter::process_single_token(const std::string &token) {

  // Operands go right onto the stack
  if (is_number(token)) {
    this->add_number_to_expression(token);
    return;
  }

  // Left parenthesis
  if (is_left_parenthesis(token)) {
    this->add_left_parenthesis(token);
    return;
  }

  // Right parenthesis
  if (is_right_parenthesis(token)) {
    this->add_right_parenthesis(token);
    return;
  }

  // Okay, treat it as a normal binary operator
  if (is_operator(token)) {
    this->process_operator(token);
    return;
  }

  // Unknown symbol! Problem!
  throw Postfix_Converter::invalid_operator_exception(token);
}

// Operands go right onto the stack
if (is_number(token)) {
  this->add_number_to_expression(token);
  return;
}

// Left parenthesis
if (is_left_parenthesis(token)) {
  this->add_left_parenthesis(token);
  return;
}

// Right parenthesis
if (is_right_parenthesis(token)) {
  this->add_right_parenthesis(token);
  return;
}

// Okay, treat it as a normal binary operator
this->process_operator(token);
}

//
// Add a number to the current expression
//
void Postfix_Converter::add_number_to_expression(const std::string &token) {

  // Two numbers in a row is not allowed
  if (this->last_token_number) {
    throw Postfix_Converter::invalid_infix_exception();
  }
  this->last_token_number = true;

  int number = std::stoi(token);
  Number_Command *num_command = factory.construct_number_command(number);
  this->expression.enqueue(num_command);
}

//
// Add an operator to the current expression
//
void Postfix_Converter::add_operator_to_expression(const std::string &token) {
  Command *command = get_operator_command(token);
  this->expression.enqueue(command);
}

//
// Use the factory method pattern to return a command
//
Command *Postfix_Converter::get_operator_command(const std::string &token) {

  // Lookup the entry in the map
  const LookupEntry *lookup = find_operation(token);
  if (lookup != nullptr) {
    return lookup->construct_object(this->factory);
  }

  throw Postfix_Converter::invalid_operator_exception(token);
}

//
// Add a left parenthesis to the expression
//
void Postfix_Converter::add_left_parenthesis(const std::string &token) {
  // Parenthesis can only come after an operator
  if (this->last_token_number) {
    throw Postfix_Converter::invalid_infix_exception();
  }
  this->stack.push(token);
}

//
// Add a right parenthesis to the expression
//
void Postfix_Converter::add_right_parenthesis(const std::string &token) {
  // Right parenthesis can only come after a number
  if (!this->last_token_number) {
    throw Postfix_Converter::invalid_infix_exception();
  }
  this->pop_until_matching_parenthesis(token);
}

//
// Logic for processing an operator (with precedence)
//
void Postfix_Converter::process_operator(const std::string &token) {

  //
  // Pop any remaining operators from the stack
  //
  void Postfix_Converter::pop_remaining_operators() {

    while (!this->stack.is_empty()) {

      std::string stack_top = stack.pop();

      // Test for any residue parenthesis
      if (is_left_parenthesis(stack_top)) {
        throw Postfix_Converter::mismatched_parenthesis_exception();
      }

      this->add_operator_to_expression(stack_top);
    }
  }

  //
  // Test if the string is a number
  //
  bool Postfix_Converter::is_number(const std::string &token) {
    // We can use the default C++ number conversion to test if it
    //  is a valid number or not
    char *p;
    strtol(token.c_str(), &p, 10);
    return *p == 0;
  }

  //
  // Test if the input is a left parenthesis or right parenthesis
  //
  bool Postfix_Converter::is_left_parenthesis(const std::string &token) {
    return (token == "(") || (token == "[");
  }

  bool Postfix_Converter::is_right_parenthesis(const std::string &token) {
    return (token == ")") || (token == "]");
  }

  bool Postfix_Converter::is_matching_parenthesis(const std::string &left,
                                                  const std::string &right) {
    return ((left == "(" && right == ")") || (left == "[" && right == "]"));
  }

  //
  // Test if the token is an operator
  //
  bool Postfix_Converter::is_operator(const std::string &token) {
    return (find_operation(token) != nullptr);
  }

  //
  // Get the operator precedence
  //
  int Postfix_Converter::get_operator_precedence(const std::string &token) {

    // Lookup the entry in the map
    const LookupEntry *lookup = find_operation(token);
    if (lookup != nullptr) {
      return lookup->precedence;
    }

    throw Postfix_Converter::invalid_operator_exception(token);
  }
