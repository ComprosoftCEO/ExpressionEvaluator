// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Postfix_Builder.h"

//Preprocessor macros
#define LAST_TOKEN_OPERAND true
#define LAST_TOKEN_OPERATOR false



//
// Constructor
//
Postfix_Builder::Postfix_Builder():
  current_state({nullptr}),
  last_token_operand(false) {}




//
// Destructor
//
Postfix_Builder::~Postfix_Builder() {

	//Free any stored expressions
	this->release_all_expressions();

	//Also release any temporary expressions
	if (this->in_expression()) {
		this->release_expression_state();
	}
}



//
// Get the last expression
//
Math_Expr* Postfix_Builder::get_expression() {
	if (this->to_free.is_empty()) {
		throw Expr_Builder::no_expression_exception();
	}

	return this->to_free.top();
}



//
// Release any stored expressions
//
void Postfix_Builder::release_all_expressions() {
	while(!this->to_free.is_empty()) {
		delete(this->to_free.pop());
	}
}


//
// Free any internal state objects
//
void Postfix_Builder::release_expression_state() {

	// Delete the current temporary state
	delete(this->current_state.expr);
	this->current_state.expr = nullptr;
	this->current_state.stack.clear();

	// Delete any stored parenthesis states
	while (!this->state_stack.is_empty()) {
		Postfix_Builder_State state = this->state_stack.pop();
		delete(state.expr);
	}
}





//
// Start a new expression
//
void Postfix_Builder::start_new_expression() {

	//Cannot start a new expression if we are already in one
	if (this->in_expression()) {
		throw Expr_Builder::invalid_action_exception();
	}


	// Create the new expression to work with
	this->current_state.expr = new Postfix_Expr();

	// Reset any other state variables (should NOT be necessary)
	this->current_state.stack.clear();
	this->state_stack.clear();
	this->last_token_operand = false;
}



//
// End the expression
//
void Postfix_Builder::end_expression() {

	//Expression must end on a number or variable
	this->test_last_token(LAST_TOKEN_OPERAND);

	//Make sure there aren't any unclosed parenthesis
	if (!this->state_stack.is_empty()) {
		throw Expr_Builder::mismatched_parenthesis_exception();
	}

	//Remove the remaining operators from the current state
	this->pop_remaining_operators();

	//Move the expression to the top of the stack
	this->to_free.push(this->current_state.expr);
	this->current_state.expr = nullptr;
}




//
// Pop the remaining operators from the stack
//
void Postfix_Builder::pop_remaining_operators() {

	while (!this->current_state.stack.is_empty()) {
		Command* command = this->current_state.stack.pop();
		this->current_state.expr->add_command(command);
	}
}



//
// Test if the builder is inside an expression
//
bool Postfix_Builder::in_expression() const {
	return (this->current_state.expr != nullptr);
}



//
// Test for a valid previous token, and throw an exception if not
//
void Postfix_Builder::test_last_token(bool expected_token) const {

	//Make sure I am inside an expression
	if (!this->in_expression()) {
		throw Expr_Builder::invalid_action_exception();
	}

	//Make sure the state is valid
	if (this->last_token_operand != expected_token) {
		throw Expr_Builder::invalid_infix_exception();
	}
}


//
// Set the new last token state
//
void Postfix_Builder::set_last_token(bool last_token) {
	this->last_token_operand = last_token;
}


//
// Add a number to the expression
//
void Postfix_Builder::build_number(int number) {

	//Number must come after an operator
	this->test_last_token(LAST_TOKEN_OPERATOR);
	this->set_last_token(LAST_TOKEN_OPERAND);

	//Create the actual number command
	Number_Command* number_command = this->factory.construct_number_command(number);
	this->current_state.expr->add_command(number_command);
}



//
// Add a variable to the expression
//
void Postfix_Builder::build_variable(const std::string& name) {

	//Variable must come after an operator
	this->test_last_token(LAST_TOKEN_OPERATOR);
	this->set_last_token(LAST_TOKEN_OPERAND);

	Variable_Command* variable_command = this->factory.construct_variable_command(name);
	this->current_state.expr->add_command(variable_command);
}



//
// Create an addition operator
//
void Postfix_Builder::build_add_operator() {
	auto construct_operator = [](Abstract_Expr_Factory& factory) -> Operator_Command* {
		return factory.construct_add_command();
	};

	this->process_operator(construct_operator);
}



//
// Create a subtraction operator
//
void Postfix_Builder::build_subtract_operator() {
	auto construct_operator = [](Abstract_Expr_Factory& factory) -> Operator_Command* {
		return factory.construct_subtract_command();
	};

	this->process_operator(construct_operator);
}



//
// Create a multiplication operator
//
void Postfix_Builder::build_multiply_operator() {
	auto construct_operator = [](Abstract_Expr_Factory& factory) -> Operator_Command* {
		return factory.construct_multiply_command();
	};

	this->process_operator(construct_operator);
}



//
// Create a division operator
//
void Postfix_Builder::build_divide_operator() {
	auto construct_operator = [](Abstract_Expr_Factory& factory) -> Operator_Command* {
		return factory.construct_divide_command();
	};

	this->process_operator(construct_operator);
}



//
// Create a modulus operator
//
void Postfix_Builder::build_modulus_operator() {
	auto construct_operator = [](Abstract_Expr_Factory& factory) -> Operator_Command* {
		return factory.construct_modulus_command();
	};

	this->process_operator(construct_operator);
}




//
// Process all operators uniformly
//
void Postfix_Builder::process_operator(std::function<Operator_Command*(Abstract_Expr_Factory&)> construct_operator) {

	//Operators can only come after a number or variable
	this->test_last_token(LAST_TOKEN_OPERAND);
	this->set_last_token(LAST_TOKEN_OPERATOR);


	//Construct the operator
	Operator_Command* op = construct_operator(this->factory);

	//Compute operator precedence
	int current_prec = op->get_precedence();
	int top_prec;



	Stack<Operator_Command*>& stack = this->current_state.stack;
	Postfix_Expr* expr = this->current_state.expr;
	do {

		//Always push if empty stack
		if (stack.is_empty()) {
			stack.push(op);
			return;
		}

		top_prec = stack.top()->get_precedence();

		//Push immediately if the current operators has a greater precedence
		if (current_prec > top_prec) {
			stack.push(op);
			return;
		}

		//For equal precedence, since we have left to right association, pop immediately
		if (current_prec == top_prec) {
			expr->add_command(stack.pop());
			stack.push(op);
			return;
		}


		//Pop the element if top precedence >= current precedence, then retest the new top
		expr->add_command(stack.pop());

	} while (current_prec < top_prec);
}




//
// Left parenthesis
//
void Postfix_Builder::build_left_parenthesis() {

	//Left parenthesis can only come after an operator
	this->test_last_token(LAST_TOKEN_OPERATOR);

	//Push the current state onto the stack
	this->state_stack.push(this->current_state);

	//Set up a new current state for the temporary expression
	this->current_state.expr = new Postfix_Expr();
	this->current_state.stack.clear();
}




//
// Right Parenthesis
//
void Postfix_Builder::build_right_parenthesis() {

	//Right parenthesis can only come after a number or variable
	this->test_last_token(LAST_TOKEN_OPERAND);

	//Underflowed the stack!
	if (this->state_stack.is_empty()) {
		throw Expr_Builder::mismatched_parenthesis_exception();
	}

	//Remove the remaining operators from the current state
	this->pop_remaining_operators();

	//Return to the previous state
	Postfix_Expr* sub_expr = this->current_state.expr;
	this->current_state = this->state_stack.pop();

	//Append the sub-expresison onto the current expression before
	// freeing it from memory
	this->current_state.expr->append_sub_expression(*sub_expr);
	delete(sub_expr);
}
