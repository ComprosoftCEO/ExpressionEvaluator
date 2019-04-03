//==============================================================================
/**
 * @file       Square_Root_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef SQUARE_ROOT_COMMAND_HEADER
#define SQUARE_ROOT_COMMAND_HEADER

#include "../Unary_Command.h"


class Square_Root_Command: public Unary_Command {

public:

	/// Default constructor
	Square_Root_Command();

	/// Call the square root method on the input
	int do_operation(int input);


	/**
	 * @class negative_square_root_exception
	 * Thrown when trying to do the square root of a negative number
	 */
	class negative_square_root_exception: public std::exception {
		const char* what() const noexcept {
			return "Trying to square root a negative number!";
		}
	};
};


#endif	/* Square Root Command Header Included */
