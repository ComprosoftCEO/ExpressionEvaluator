//==============================================================================
/**
 * @file       Postfix_Builder.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef POSTFIX_BUILDER_HEADER
#define POSTFIX_BUILDER_HEADER


#include "Expr_Builder.h"
#include <Postfix_Expr.h>
#include <Flyweight_Expr_Factory.h>
#include <Stack.h>
#include <functional>




/**
 * @class Postfix_Builder_State
 * Struct to wrap the intermediate state of the postfix expression builder
 */
struct Postfix_Builder_State {

	/// Current expression being worked on
	Postfix_Expr* expr;

	/// Temporary stack of operators
	Stack<Operator_Command*> stack;
};




/**
 * @class Postfix_Builder
 *
 * Create a postfix expression using the builder interface
 */
class Postfix_Builder: public Expr_Builder {


public:

	/// Default Constructor
	Postfix_Builder();

	/// Destructor
	~Postfix_Builder();

	/**
	 * Get the last valid expression. If the builder is currently creating
	 * a new expression (in_expression() is true), then it throws an exception.
	 *
	 * @return			Last created expression
	 */
	Math_Expr* get_expression();

	/// Free any previously constructed expressions from memory.
	void release_all_expressions();

	/// Stop and release the current expression prematurely
	void release_expression_state();

	/// Signal to the builder to start creating a new expression
	void start_new_expression();

	/// Signal to the builder that there are no more tokens in the expression
	void end_expression();

	/**
	 * Test if the builder is currently creating an expression. This is true
	 * when start_new_expression() has been called and end_expression() has not
	 * been called.
	 *
	 * @retval			true			The builder is in an expression
	 * @retval			false			The builder is not in an expression
	 */
	bool in_expression() const;

	/**
	 * Add a integer literal to the expression
	 * @param[in]		number		Integer value to add
	 */
	void build_number(int number);

	/**
	 * Add a variable to the expression
	 * @param[in]		name		Name of the variable
	 */
	void build_variable(const std::string& name);

	/// Add a + operator to the expression
	void build_add_operator();

	/// Add a - operator to the expression
	void build_subtract_operator();

	/// Add a * operator to the expression
	void build_multiply_operator();

	/// Add a / operator to the expression
	void build_divide_operator();

	/// Add a % operator to the expression
	void build_modulus_operator();

	/// Add a ( to the expression
	void build_left_parenthesis();

	/// Add a ) to the expression
	void build_right_parenthesis();



private:

	/**
	 * Pop any additional operators from the stack and add them to the expression
	 */
	void pop_remaining_operators();

	/**
	 * All of the logic required to process an operator
	 * @param[in]		op			The operator to process
	 */
	void process_operator(std::function<Operator_Command*(Abstract_Expr_Factory&)> construct_operator);

private:

	/// Factory used to create the Command objects
	Flyweight_Expr_Factory factory;

	/// List of previous expressions to free
	/// The top of the stack is the last expression computed
	Stack<Postfix_Expr*> to_free;

	/// Current expression state
	Postfix_Builder_State current_state;

	/// Stack of states for handling parenthesis
	Stack<Postfix_Builder_State> state_stack;

	/// True if the last streamed-in token was a number or variable
	bool last_token_operand;
};



#endif	/* Postfix Builder Header Included */
