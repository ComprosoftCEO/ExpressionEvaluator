#include <iostream>
#include <string>
#include <exception>

#include <Queue.h>
#include <Postfix_Expr_Factory.h>
#include "Postfix_Converter.h"


//Internal methods
static Queue<std::string> read_input_expression(void);
static void run_postfix_expression(Queue<Command*> expression);


int main(void) {

	try {

		Stack<int> result;
		Postfix_Expr_Factory factory(result);
		Postfix_Converter converter(factory);

		//Read the infix expression from user input
		Queue<std::string> infix_expr = read_input_expression();
	
		//Convert the expression to postfix
		Queue<Command*> postfix_expr = converter.convert_to_postfix(infix_expr);

		//Run the expression and print to cout
		run_postfix_expression(postfix_expr);
		std::cout << result.top() << std::endl;


	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "Unknown Exception!" << std::endl;
	}

	return 0;
}




//
// Read an expression from std::cin and tokenize it
//
static Queue<std::string> read_input_expression() {

	Queue<std::string> expression;
	std::string input;

	std::cin >> input;
	while (input != "QUIT") {
		expression.enqueue(input);
		std::cin >> input;
	}

	return expression;
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
