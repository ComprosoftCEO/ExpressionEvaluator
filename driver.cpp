#include <iostream>
#include <string>
#include <exception>

#include <Queue.h>
#include <Postfix_Expr_Factory.h>
#include "Postfix_Converter.h"


//Internal methods
static void parse_and_run_expression(const std::string& infix_expr);
static void run_postfix_expression(Queue<Command*> expression);


int main(void) {

	try {

		std::cout << "Enter Expression: ";

		//Loop until the word QUIT or the end of the stream
		std::string expr;
		while (std::getline(std::cin, expr) && (expr != "QUIT")) {
			parse_and_run_expression(expr);
			std::cout << "Enter Expression: ";
		}

	} catch (...) {
		std::cout << "Unknown Exception!" << std::endl;
	}



	return 0;
}




//
// Parse and run a single expression
//
static void parse_and_run_expression(const std::string& infix_expr) {
	try {

		Stack<int> result;
		Postfix_Expr_Factory factory(result);
		Postfix_Converter converter(factory);

		//Convert the expression to postfix
		Queue<Command*> postfix_expr = converter.convert_to_postfix(infix_expr);

		//Run the expression and print to cout
		run_postfix_expression(postfix_expr);
		std::cout << result.top() << std::endl;


	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	} catch (...) {
		std::cout << "Unknown Exception!" << std::endl;
	}
}



//
// Run the expression
//
static void run_postfix_expression(Queue<Command*> expression) {
	while (!expression.is_empty()) {
		Command* command = expression.dequeue();
		command->execute();
	}
}
