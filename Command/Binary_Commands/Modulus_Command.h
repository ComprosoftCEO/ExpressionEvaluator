//==============================================================================
/**
 * @file       Modulus_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef MODULUS_COMMAND_HEADER
#define MODULUS_COMMAND_HEADER

#include "../Binary_Command.h"
#include <exception>



class Modulus_Command: public Binary_Command {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack		Reference to the stack of integers
	 */
	Modulus_Command(Stack<int>& stack);

	/// Do left mod right
	int do_operation(int left, int right);


	/**
	 * @class modulus_zero_exception
	 * Thrown when trying to do a number modulus 0
	 */
	class modulus_zero_exception: public std::exception {
		const char* what() const noexcept {
			return "Floating point exception: modulus 0!";
		}
	};
};


#endif	/* Add Command Header Included */

