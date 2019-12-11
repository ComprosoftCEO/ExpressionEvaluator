// User interface implementation

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include "User_Interface.h"

#include <Postfix_Calculator.h>
#include <Tree_Calculator.h>
#include <exception>
#include <iostream>
#include <limits>  /* For std::numeric_limits */
#include <sstream> /* For integer parsing */

//
// Main method
//
void User_Interface::run(void) noexcept {

  try {

    std::cout << "Enter Math Expression: ";

    // Loop until the word QUIT or the end of the stream
    std::string expr;
    while (std::getline(std::cin, expr) && (expr != "QUIT")) {
      this->parse_and_run_expression(expr);
      std::cout << "Enter Math Expression: ";
    }

  } catch (...) { std::cout << "Unknown Exception!" << std::endl; }
}

//
// Parse an infix expression, calculate it, then print the result
//
void User_Interface::parse_and_run_expression(const std::string& infix_expr) noexcept {
  try {

    Tree_Calculator calculator;

    // Parse the math expression
    Math_Expr* expr = calculator.parse_infix_expression(infix_expr);

    // Get the user to input all variables
    std::map<std::string, int> lookup = expr->get_variable_values();
    ask_for_variables(lookup);
    expr->set_variable_values(lookup);

    // Run the expression and print to cout
    std::cout << expr->evaluate() << std::endl;

  } catch (std::exception& e) { std::cout << "Error: " << e.what() << std::endl; } catch (...) {
    std::cout << "Unknown Exception!" << std::endl;
  }
}

//
// Ask the user to input variables in alphabetical order
//
void User_Interface::ask_for_variables(std::map<std::string, int>& lookup) {

  // Map is automatically in alphabetical order
  for (auto it = lookup.begin(); it != lookup.end(); ++it) {
    it->second = get_integer("Variable \"" + it->first + "\"");
  }
}

//
// Ask the user to input an integer
//
int User_Interface::get_integer(const std::string& prompt) {

  int value;
  while (true) {

    std::cout << prompt << " = ";

    // Read a line from std::cin
    std::string str_number;
    std::getline(std::cin, str_number);
    std::stringstream convert(str_number);

    // Checks for a valid integer, making sure there it *can* convert
    //  to an integer and has no leftover character data
    if ((convert >> value) && !(convert >> str_number)) { return value; }

    // Clear any errors and try again
    std::cin.clear();
    std::cout << "Invalid Integer!" << std::endl;
  }
}
