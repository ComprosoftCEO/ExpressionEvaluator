// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Postfix_Converter.h"



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
Queue<Command*> Postfix_Converter::convert_to_postfix(Queue<std::string> infix_expr) {

	this->free_allocated_commands();

	try {	
	
		while (!infix_expr.is_empty()) {
			std::string token = infix_expr.dequeue();
			this->process_single_token(token);
		}

		// Add any other elements from the stack
		this->pop_remaining_operators();

		return this->expression;

	} catch (...) {
		// Try to catch any potential memory leaks
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
		this->stack.push(token);
		return;
	}

	//Right parenthesis
	if (is_right_parenthesis(token)) {
		this->pop_until_matching_parenthesis(token);
		return;
	}


	//Compute operator precedence
	int current_prec = get_operator_precedence(token);


retest:

	//Always push if empty stack or last operator is left parenthesis
	if (this->stack.is_empty() || is_left_parenthesis(this->stack.top())) {
		this->stack.push(token);
		return;
	}

	//Compare to top operator precedence
	int top_prec = get_operator_precedence(this->stack.top());

	//Pop the elements if top precedence >= current precedence, then retest the new top
	if (current_prec < top_prec) {
		this->add_operator_to_expression(this->stack.pop());
		goto retest;
	}

	if (current_prec > top_prec) {
		//Push greater precedence
		this->stack.push(token);
		return;
	} else if (current_prec == top_prec) {
		//Since we have left to right association, pop immediately
		this->add_operator_to_expression(this->stack.pop());
		this->stack.push(token);
		return;
	}
}





//
// Add a number to the current expression
//
void Postfix_Converter::add_number_to_expression(const std::string& token) {
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
