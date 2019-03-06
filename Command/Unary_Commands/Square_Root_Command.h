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

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack		Reference to the stack of integers
	 */
	Square_Root_Command(Stack<int>& stack);

	/// Call the square root method on the input
	int do_operation(int input);

};


#endif	/* Square Root Command Header Included */
