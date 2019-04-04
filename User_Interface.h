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
	 * Read the input string, parse the infix expression, run the expression,
	 *  and print the result to standard output.
	 *
	 * @param[in]		infix_expr		The infix expression to parse
	 */
	void parse_and_run_expression(const std::string& infix_expr) noexcept;
};

#endif	/* User Interface Header Included */
