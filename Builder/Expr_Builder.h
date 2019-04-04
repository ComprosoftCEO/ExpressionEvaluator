//==============================================================================
/**
 * @file       Expr_Builder.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef EXPR_BUILDER_HEADER
#define EXPR_BUILDER_HEADER

#include "Math_Expr.h"
#include <exception>
#include <string>


/**
 * @class Expr_Builder
 *
 * Create an internal representation of an expression by reading a sequence of infix
 * tokens. Before streaming tokens into the builder, the start_new_expression() method
 * method should be called to properly initialize the state. Then, tokens can be 
 * streamed into the builder one-by-one by calling the various build_* methods. After
 * all of the tokens have been read and inputted into the builder, call end_expression()
 * to finish up any expression logic. Use get_expression() to return the last computed
 * math expression. No tokens should be streamed into the builder before calling start()
 * or after calling end() (it should throw an exception).
 *
 * If an invalid token is streamed into the builder at any point, then the builder may
 * throw an exception to signal that the infix expression is not valid. The state of
 * the builder will NOT be modified so the client can continue streaming tokens into the
 * object's internal memory.
 *
 * It is the responsibility of the builder subclass to maintain and free all resources,
 * including the expression, after use. The client should NOT call delete on the pointer
 * returned by get_expression(). A call to start_new_expression() will NOT delete any
 * previously constructed expressions. The method release_all_expressions() can be used to
 * manually free any previosly allocated expressions, at which case using these expressions
 * will become invalid.
 *
 * A expression being built can be terminated early by calling release_expression_state().
 * If this method is called, then any temporary data is deleted and in_expression() is
 * reset to false. If the program is not in an expression, then an exception should be thrown.
 */
class Expr_Builder {

public:
	//All of the exceptions for the builder class
	#include "Builder_Exceptions.h"

public:

	/// Destructor
	virtual ~Expr_Builder() = default;

	/**
	 * Get the last valid expression. If the builder is currently creating
	 * a new expression (in_expression() is true), then it throws an exception.
	 *
	 * @return			Last created expression
	 */
	virtual Math_Expr* get_expression() = 0;

	/// Free any previously constructed expressions from memory.
	virtual void release_all_expressions() = 0;

	/// Stop and release the current expression prematurely
	virtual void release_expression_state() = 0;

	/// Signal to the builder to start creating a new expression
	virtual void start_new_expression() = 0;

	/// Signal to the builder that there are no more tokens in the expression
	virtual void end_expression() = 0;

	/**
	 * Test if the builder is currently creating an expression. This is true
	 * when start_new_expression() has been called and end_expression() has not
	 * been called.
	 *
	 * @retval			true			The builder is in an expression
	 * @retval			false			The builder is not in an expression
	 */
	virtual bool in_expression() const = 0;

	/**
	 * Add a integer literal to the expression
	 * @param[in]		number		Integer value to add
	 */
	virtual void build_number(int number) = 0;

	/**
	 * Add a variable to the expression
	 * @param[in]		name		Name of the variable
	 */
	virtual void build_variable(const std::string& name) = 0;

	/// Add a + operator to the expression
	virtual void build_add_operator() = 0;

	/// Add a - operator to the expression
	virtual void build_subtract_operator() = 0;

	/// Add a * operator to the expression
	virtual void build_multiply_operator() = 0;

	/// Add a / operator to the expression
	virtual void build_divide_operator() = 0;

	/// Add a % operator to the expression
	virtual void build_modulus_operator() = 0;

	/// Add a ( to the expression
	virtual void build_left_parenthesis() = 0;

	/// Add a ) to the expression
	virtual void build_right_parenthesis() = 0;
};

#endif	/* Expression Builder Header Included */
