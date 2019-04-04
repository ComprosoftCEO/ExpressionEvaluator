// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Tree_Builder.h"
#include <Number_Node.h>
#include <Add_Node.h>
#include <Subtract_Node.h>
#include <Multiply_Node.h>
#include <Divide_Node.h>
#include <Modulus_Node.h>



//
// Constructor
//
Tree_Builder::Tree_Builder():
  last_token_operand(false),
  inside_expression(false) {}



//
// Destructor
//
Tree_Builder::~Tree_Builder() {
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
Math_Expr* Tree_Builder::get_expression() {
	if (this->in_expression()) {
		//TODO: Throw an exception
	}

	if (this->to_free.is_empty()) {
		//TODO: Throw an exception
	}

	return this->to_free.top();
}




//
// Release any stored expressions
//
void Tree_Builder::release_all_expressions() {
	while(!this->to_free.is_empty()) {
		delete(this->to_free.pop());
	}
}




//
// Free any internal state objects
//
void Tree_Builder::release_expression_state() {

	//Delete anything in all states
	this->state_stack.push(current_state);
	while(!this->state_stack.is_empty()) {
		Tree_Builder_State state = this->state_stack.pop();

		// Free the expression stack
		while (!state.expr_stack.is_empty()) {
			delete(state.expr_stack.pop());
		}

		// Free the temporary operator stack
		while(!state.operator_stack.is_empty()) {
			delete(state.operator_stack.pop());
		}
	}

	this->inside_expression = false;
	this->last_token_operand = false;
}




//
// Start a new expression
//
void Tree_Builder::start_new_expression() {

	if (this->in_expression()) {
		//TODO: Throw an exception
	}

	// Create the new expression to work with
	this->inside_expression = true;
	this->last_token_operand = false;
}



//
// End the expression
//
void Tree_Builder::end_expression() {

	//Must be in an expression to end it
	if (!this->in_expression()) {
		//TODO: Throw an exception
	}

	//Make sure there aren't any unclosed parenthesis
	if (!this->state_stack.is_empty()) {
		//TODO: Throw an exception
	}

	//Expression must end on a valid token
	if (!this->last_token_operand) {
		//TODO: throw an exception
	}

	//Remove the remaining operators from the current state
	this->pop_remaining_operators();

	//Move the top expression to the to free stack
	Expr_Node* root = this->current_state.expr_stack.top();
	this->to_free.push(new Tree_Expr(root));
	this->inside_expression = false;
}



//
// Pop the remaining operators from the stack
//
void Tree_Builder::pop_remaining_operators() {

	Tree_Builder_State& state = this->current_state;
	while (!state.operator_stack.is_empty()) {
		Operator_Node* op = state.operator_stack.pop();
		this->push_operator(op);
	}
}



//
// Test if the builder is inside an expression
//
bool Tree_Builder::in_expression() const {
	return this->inside_expression;
}



//
// Add a number to the expression
//
void Tree_Builder::build_number(int number) {

	//Must be inside an expression
	if (!this->in_expression()) {
		//TODO: Throw an exception
	}

	//Number must come after an operator
	if (this->last_token_operand) {
		//TODO: Throw an exception
	}
	this->last_token_operand = true;


	//Create the actual number command
	Number_Node* number_node = new Number_Node(number);
	this->current_state.expr_stack.push(number_node);
}


//
// Add a varaible to the expression
//
void Tree_Builder::build_variable(const std::string& name) {

	//Must be inside an expression
	if (!this->in_expression()) {
		//TODO: Throw an exception
	}

	//Variable must come after an operator
	if (this->last_token_operand) {
		//TODO: Throw an exception
	}
	this->last_token_operand = true;


	//TODO: Get this method working
}



//
// Create an addition operator
//
void Tree_Builder::build_add_operator() {
	this->process_operator(
		[]() -> Operator_Node* {return new Add_Node();}
	);
}



//
// Create a subtraction operator
//
void Tree_Builder::build_subtract_operator() {
	this->process_operator(
		[]() -> Operator_Node* {return new Subtract_Node();}
	);
}



//
// Create a multiplication operator
//
void Tree_Builder::build_multiply_operator() {
	this->process_operator(
		[]() -> Operator_Node* {return new Multiply_Node();}
	);
}



//
// Create a division operator
//
void Tree_Builder::build_divide_operator() {
	this->process_operator(
		[]() -> Operator_Node* {return new Divide_Node();}
	);
}



//
// Create a modulus operator
//
void Tree_Builder::build_modulus_operator() {
	this->process_operator(
		[]() -> Operator_Node* {return new Modulus_Node();}
	);
}




//
// Process all operators uniformly
//
void Tree_Builder::process_operator(std::function<Operator_Node*(void)> construct_operator) {

	//Must be inside an expression
	if (!this->in_expression()) {
		//TODO: Throw an exception
	}

	//Operators can only come after a number or variable
	if (!this->last_token_operand) {
		//TODO: Throw an exception
	}
	this->last_token_operand = false;


	//Construct the operator
	Operator_Node* op = construct_operator();

	//Compute operator precedence
	int current_prec = op->get_precedence();
	int top_prec;



	Stack<Operator_Node*>& operator_stack = this->current_state.operator_stack;
	do {

		//Always push if empty stack
		if (operator_stack.is_empty()) {
			operator_stack.push(op);
			return;
		}

		top_prec = operator_stack.top()->get_precedence();

		//Push immediately if the current operators has a greater precedence
		if (current_prec > top_prec) {
			operator_stack.push(op);
			return;
		}

		//For equal precedence, since we have left to right association, pop immediately
		if (current_prec == top_prec) {
			this->push_operator(operator_stack.pop());
			operator_stack.push(op);
			return;
		}


		//Pop the element if top precedence >= current precedence, then retest the new top
		this->push_operator(operator_stack.pop());

	} while (current_prec < top_prec);
}




//
// Push an operator onto the temporary expression stack
//
void Tree_Builder::push_operator(Operator_Node* op) {

	//Load the left and right children, then push back onto the stack
	op->load_children_from_stack(this->current_state.expr_stack);
	this->current_state.expr_stack.push(op);
}



//
// Left parenthesis
//
void Tree_Builder::build_left_parenthesis() {

	//Left parenthesis can only come after an operator
	if (this->last_token_operand) {
		//TODO: Throw an exception
	}

	//Push the current state onto the stack
	this->state_stack.push(this->current_state);

	//Set up a new current state for the temporary expression
	this->current_state.operator_stack.clear();
	this->current_state.expr_stack.clear();
}




//
// Right Parenthesis
//
void Tree_Builder::build_right_parenthesis() {

	//Overflowed the stack!
	if (this->state_stack.is_empty()) {
		//TODO: Throw an exception
	}

	//Right parenthesis can only come after a number or variable
	if (!this->last_token_operand) {
		//TODO: Throw an exception
	}


	//Remove the remaining operators from the current state
	this->pop_remaining_operators();

	//Return to the previous state
	Expr_Node* sub_expr = this->current_state.expr_stack.top();
	this->current_state = this->state_stack.pop();

	//Push the sub expression onto the queue
	this->current_state.expr_stack.push(sub_expr);
}
