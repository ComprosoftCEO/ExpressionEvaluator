//User interface implementation

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include "User_Interface.h"
#include "Postfix_Converter.h"
#include <Flyweight_Expr_Factory.h>
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
// Parse an expression using the infix to postfix class, then run and compute the result
//
void User_Interface::parse_and_run_expression(const std::string& infix_expr) noexcept {
	try {

		Stack<int> result;
		Flyweight_Expr_Factory factory(result);
		Postfix_Converter converter(factory);

		//Convert the expression to postfix
		Queue<Command*> postfix_expr = converter.convert_to_postfix(infix_expr);

		//Run the expression and print to cout
		this->run_postfix_expression(postfix_expr);
		std::cout << result.top() << std::endl;


	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	} catch (...) {
		std::cout << "Unknown Exception!" << std::endl;
	}
}




//
// Compute the result of the expression
//
void User_Interface::run_postfix_expression(Queue<Command*>& expression) {
	while (!expression.is_empty()) {
		Command* command = expression.dequeue();
		command->execute();
	}
}

