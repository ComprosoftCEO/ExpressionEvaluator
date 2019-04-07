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
#include <map>


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
	static void parse_and_run_expression(const std::string& infix_expr) noexcept;

	/**
	 * Ask the user to input the variable values in alphabetical order
	 * @param[in,out]	lookup			Map used to store the variable values
	 */
	static void ask_for_variables(std::map<std::string, int>& lookup);

	/**
	 * Ask the user to enter an integer. Keeps looping until a valid integer
	 * is entered.
	 *
	 * @param[in]		message			Prompt for each line
	 * @return			Inputted integer
	 */
	static int get_integer(const std::string& prompt);

};

#endif	/* User Interface Header Included */
