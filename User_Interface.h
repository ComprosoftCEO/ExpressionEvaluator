//==============================================================================
/**
 * @file       User_Interface.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef USER_INTERFACE_HEADER
#define USER_INTERFACE_HEADER

#include <string>
#include <Command.h>
#include <Queue.h>


/**
 * @class User_Interface
 * Defines a series of methods for entering and evaluating the expressions
 */
class User_Interface {

public:

	/// Ask expressions from the user until the word QUIT is typed
	void run(void) noexcept;

private:

	/**
	 * Read the input string, convert the string from an infix to postfix
	 *  expression, then run the converted expression and print the output.
	 *
	 * @param[in]		infix_expr		The infix expression to convert
	 */
	void parse_and_run_expression(const std::string& infix_expr) noexcept;

	/**
	 * Execute the queue of commands to compute the actual expression
	 *
	 * @param[in,out]	expression		The queue of expressions to run
	 */
	int run_postfix_expression(Queue<Command*>& expression);
};

#endif	/* User Interface Header Included */
