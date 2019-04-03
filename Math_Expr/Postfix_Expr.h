//==============================================================================
/**
 * @file       Postfix_Expr.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef POSTFIX_EXPR_HEADER
#define POSTFIX_EXPR_HEADER

#include "Math_Expr.h"
#include <Command.h>
#include <Array.h>
#include <Stack.h>


/**
 * @class Postfix_Expr
 *
 * Stores the expression as an array of commands to execute. Since the
 * commands are constructed from a factory, this class is not responsible
 * for freeing the commands.
 */
class Postfix_Expr: public Math_Expr {

public:

	/// Evaluate the postfix expression
	int evaluate();

	/**
	 * Add a command into the expression to evaluate
	 *
	 * @param[in]		command			The command to add to the expression
	 */
	void add_command(Command* command);

	/**
	 * Add all of the commands from the sub expression onto the current expression.
	 * @param[in]		expr			Expression object to copy the commands from
	 */
	void append_sub_expression(const Postfix_Expr& expr);

private:
	/// Array of commands to run
	Array<Command*> to_run_;

	/// Stack of integers used during evaluation
	Stack<int> stack_;
};


#endif	/* Postfix Expression Header Included */
