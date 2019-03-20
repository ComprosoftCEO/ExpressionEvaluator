// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Postfix_Converter.h"
#include <sstream>



//
// Constructor
//
Postfix_Converter::Postfix_Converter(Abstract_Expr_Factory& factory):
  factory(factory) {}



//
// Destructor
//
Postfix_Converter::~Postfix_Converter() {
	this->free_allocated_commands();
}




//
// Convert an expression to postfix
//
Queue<Command*> Postfix_Converter::convert_to_postfix(const std::string& infix_expr) {

	//Reset the parser state
	this->free_allocated_commands();
	this->last_token_number = false;

	try {

		std::stringstream ss(infix_expr);
		std::string token;
		while (ss >> token) {
			this->process_single_token(token);
		}

		// Add any other elements from the stack
		this->pop_remaining_operators();

		return this->expression;

	} catch (...) {
		// Try to catch any potential memory leaks before rethrowing the exception
		this->free_allocated_commands();
		throw;
	}
}




//
// Process a single token
//
void Postfix_Converter::process_single_token(const std::string& token) {

	//Operands go right onto the stack
	if (is_number(token)) {
		this->add_number_to_expression(token);
		return;
	}

	//Left parenthesis
	if (is_left_parenthesis(token)) {
		this->add_left_parenthesis(token);
		return;
	}

	//Right parenthesis
	if (is_right_parenthesis(token)) {
		this->add_right_parenthesis(token);
		return;
	}

	//Okay, treat it as a normal binary operator
	this->process_operator(token);
}





//
// Add a number to the current expression
//
void Postfix_Converter::add_number_to_expression(const std::string& token) {

	//Two numbers in a row is not allowed
	if (this->last_token_number) {
		throw Postfix_Converter::invalid_infix_exception();
	}
	this->last_token_number = true;

	int number = std::stoi(token);
	Number_Command* num_command = factory.construct_number_command(number);
	this->expression.enqueue(num_command);
}


//
// Add an operator to the current expression
//
void Postfix_Converter::add_operator_to_expression(const std::string& token) {
	Binary_Command* binary_command = get_binary_command(token);
	this->expression.enqueue(binary_command);
}

//
// Use the factory method pattern to return a binary command
//
Binary_Command* Postfix_Converter::get_binary_command(const std::string& token) {

	//I hate these if statements. Is there a better way?
	if (token == "+") {
		return this->factory.construct_add_command();
	} else if (token == "-") {
		return this->factory.construct_subtract_command();
	} else if (token == "*") {
		return this->factory.construct_multiply_command();
	} else if (token == "/") {
		return this->factory.construct_divide_command();
	} else if (token == "%") {
		return this->factory.construct_modulus_command();
	}	

	throw Postfix_Converter::invalid_operator_exception(token);
}


//
// Add a left parenthesis to the expression
//
void Postfix_Converter::add_left_parenthesis(const std::string& token) {
	//Parenthesis can only come after an operator
	if (this->last_token_number) {
		throw Postfix_Converter::invalid_infix_exception();
	}
	this->stack.push(token);
}


//
// Add a right parenthesis to the expression
//
void Postfix_Converter::add_right_parenthesis(const std::string& token) {
	// Right parenthesis can only come after a number
	if (!this->last_token_number) {
		throw Postfix_Converter::invalid_infix_exception();
	}
	this->pop_until_matching_parenthesis(token);
}



//
// Logic for processing an operator (with precedence)
//
void Postfix_Converter::process_operator(const std::string& token) {


	//Compute operator precedence
	//  Might throw an invalid operator exception
	int current_prec = get_operator_precedence(token);
	int top_prec;

	//Operators can only come after a number
	if (!this->last_token_number) {
		throw Postfix_Converter::invalid_infix_exception();
	}
	this->last_token_number = false;


	do {

		//Always push if empty stack or last operator is left parenthesis
		if (this->stack.is_empty() || is_left_parenthesis(this->stack.top())) {
			this->stack.push(token);
			return;
		}

		top_prec = get_operator_precedence(this->stack.top());

		//Push immediately if the current operators has a greater precedence
		if (current_prec > top_prec) {
			this->stack.push(token);
			return;
		}

		//For equal precedence, since we have left to right association, pop immediately
		if (current_prec == top_prec) {
			this->add_operator_to_expression(this->stack.pop());
			this->stack.push(token);
			return;
		}


		//Pop the element if top precedence >= current precedence, then retest the new top
		this->add_operator_to_expression(this->stack.pop());

	} while (current_prec < top_prec);
}



//
// Keep popping until the corresponding parenthesis is found
//
void Postfix_Converter::pop_until_matching_parenthesis(const std::string& right_paren) {

	bool paren_found = false;
	
	do {

		// Empty Stack = no more possible parenthesis
		if (this->stack.is_empty()) {
			throw Postfix_Converter::mismatched_parenthesis_exception();
		}

		//Get the top operator from the stack
		std::string stack_top = stack.pop();

		//Find first left parenthesis character on the stack
		if (is_left_parenthesis(stack_top)) {
			if (is_matching_parenthesis(stack_top, right_paren)) {
				paren_found = true;

			} else {
				// Different types of parenthesis in wrong order
				//   for example: ([   )]
				throw Postfix_Converter::mismatched_parenthesis_exception();
			}
		}

		//We are not at the parenthesis yet, so add operator to the expression
		if (!paren_found) {
			this->add_operator_to_expression(stack_top);
		}

	} while (!paren_found);
}



//
// Pop any remaining operators from the stack
//
void Postfix_Converter::pop_remaining_operators() {

	while (!this->stack.is_empty()) {

		std::string stack_top = stack.pop();

		//Test for any residue parenthesis
		if (is_left_parenthesis(stack_top)) {
			throw Postfix_Converter::mismatched_parenthesis_exception();
		}

		this->add_operator_to_expression(stack_top);
	}
}




//
// Free any allocated commands
//
void Postfix_Converter::free_allocated_commands() {
	while (!this->expression.is_empty()) {
		delete(this->expression.dequeue());
	}
}






//
// Test if the string is a number
//
bool Postfix_Converter::is_number(const std::string& token) {
	//We can use the default C++ number conversion to test if it
	//  is a valid number or not
	char* p;
	strtol(token.c_str(), &p, 10);
	return *p == 0;
}




//
// Test if the input is a left parenthesis or right parenthesis
//
bool Postfix_Converter::is_left_parenthesis(const std::string& token) {
	return (token == "(") || (token == "[");
}

bool Postfix_Converter::is_right_parenthesis(const std::string& token) {
	return (token == ")") || (token == "]");
}

bool Postfix_Converter::is_matching_parenthesis(const std::string& left, const std::string& right) {
	return (
		(left == "(" && right == ")") || 
		(left == "[" && right == "]")
	);
}



//
// Get the operator precedence
//
int Postfix_Converter::get_operator_precedence(const std::string& token) {

	if (token == "+" || token == "-") {
		return 1;
	} else if (token == "*" || token == "/" || token == "%") {
		return 2;
	}

	throw Postfix_Converter::invalid_operator_exception(token);
}
