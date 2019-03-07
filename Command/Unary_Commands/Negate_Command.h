//==============================================================================
/**
 * @file       Negate_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef NEGATE_COMMAND_HEADER
#define NEGATE_COMMAND_HEADER

#include "../Unary_Command.h"


class Negate_Command: public Unary_Command {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack		Reference to the stack of integers
	 */
	Negate_Command(Stack<int>& stack);

	/// Multiply input by -1
	int do_operation(int input);

};


#endif	/* Negate Command Header Included */
