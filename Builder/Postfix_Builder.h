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
	 * Get the last valid expression.
	 *
	 * @return			Last created expression
	 * @throws			no_expression_exception		An expression has not yet been created
	 */
	Math_Expr* get_expression();

	/// Free any previously constructed expressions from memory.
	void release_all_expressions();

	/// Stop and release the current expression prematurely
	void release_expression_state();

	/**
	 * Signal to the builder to start creating a new expression
	 *
	 * @throws			invalid_action_exception	Already inside an expression
	 */
	void start_new_expression();

	/**
	 * Signal to the builder that there are no more tokens in the expression
	 *
	 * @throws			invalid_action_exception			Not inside an expression
	 * @throws			mismatched_parenthesis_exception	Unclosed parenthesis in expression
	 */
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
	 *
	 * @param[in]		number							Integer value to add
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
	 */
	void build_number(int number);

	/**
	 * Add a variable to the expression
	 *
	 * @param[in]		name							Name of the variable
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
	 */
	void build_variable(const std::string& name);

	/**
	 * Add a + operator to the expression
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
	 */
	void build_add_operator();

	/**
	 * Add a - operator to the expression
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
	 */
	void build_subtract_operator();

	/**
	 * Add a * operator to the expression
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
	 */
	void build_multiply_operator();

	/**
	 * Add a / operator to the expression
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
	 */
	void build_divide_operator();

	/**
	 * Add a % operator to the expression
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
	 */
	void build_modulus_operator();

	/**
	 * Add a ( to the expression
	 *
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
	 */
	void build_left_parenthesis();

	/**
	 * Add a ) to the expression
	 *
	 * @throws			invalid_action_exception			Not inside an expression
	 * @throws			invalid_infix_exception				Invalid infix expression token
	 * @throws			mismatched_parenthesis_exception	Unclosed parenthesis in expression
	 */
	void build_right_parenthesis();



private:

	/**
	 * Test if the function call is in a token valid state, and throw an exception if not
	 * For the expression to be in a valid state, it must be BOTH inside an expression
	 * and the expected token must match with last_token_operand.
	 *
	 * @param[in]		expected_token		Expected state for the "last_token_operand" flag
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Last token does not match expected last token
	 */
	void test_last_token(bool expected_token) const;

	/**
	 * Set the new last token state for the parser
	 * @param[in]		last_token			New state for the last token
	 */
	void set_last_token(bool last_token);

	/**
	 * Pop any additional operators from the stack and add them to the expression
	 */
	void pop_remaining_operators();

	/**
	 * All of the logic required to process an operator
	 *
	 * @param[in]		op			The operator to process
	 * @throws			invalid_action_exception		Not inside an expression
	 * @throws			invalid_infix_exception			Invalid infix expression token
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
