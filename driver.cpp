#include <iostream>
#include <string>
#include <Queue.h>


//Internal methods
static Queue<std::string> read_input_expression(void);



int main(void) {

	//Read the infix expression from user input
	Queue<std::string> infix_expression = read_input_expression();

	//TODO: Convert the infix expression to postfix

	//TODO: Build and execute the expression using abstract factory

	return 0;
}




//
// Read an expression from std::cin
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
