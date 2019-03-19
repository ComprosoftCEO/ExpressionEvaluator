//==============================================================================
/**
 * @file       Divide_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef DIVIDE_COMMAND_HEADER
#define DIVIDE_COMMAND_HEADER

#include "../Binary_Command.h"
#include <exception>


class Divide_Command: public Binary_Command {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack		Reference to the stack of integers
	 */
	Divide_Command(Stack<int>& stack);

	/// Divide the left and right operators
	int do_operation(int left, int right);

	/**
	 * @class divide_by_zero_exception
	 * Thrown when trying to do a number divided by 0
	 */
	class divide_by_zero_exception: public std::exception {
		const char* what() const noexcept {
			return "Floating point exception: divide by 0!";
		}
	};
};


#endif	/* Divide Command Header Included */
