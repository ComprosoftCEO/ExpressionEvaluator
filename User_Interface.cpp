//User interface implementation

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include "User_Interface.h"
#include "Calculator.h"
#include <Postfix_Builder.h>
#include <Tree_Builder.h>
#include <iostream>
#include <exception>



//
// Main method
//
void User_Interface::run(void) noexcept {

	try {

		std::cout << "Enter Expression: ";

		//Loop until the word QUIT or the end of the stream
		std::string expr;
		while (std::getline(std::cin, expr) && (expr != "QUIT")) {
			this->parse_and_run_expression(expr);
			std::cout << "Enter Expression: ";
		}

	} catch (...) {
		std::cout << "Unknown Exception!" << std::endl;
	}
}



//
// Parse an infix expression, calculate it, then print the result
//
void User_Interface::parse_and_run_expression(const std::string& infix_expr) noexcept {
	try {

		Tree_Builder builder;
		Calculator calculator(builder);

		//Parse the math expression
		Math_Expr* expr = calculator.parse_expression(infix_expr);

		//Run the expression and print to cout
		std::cout << expr->evaluate() << std::endl;


	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	} catch (...) {
		std::cout << "Unknown Exception!" << std::endl;
	}
}
