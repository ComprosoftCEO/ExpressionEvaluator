//==============================================================================
/**
 * @file       Multiply_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef MULTIPLY_COMMAND_HEADER
#define MULTIPLY_COMMAND_HEADER

#include "../Binary_Command.h"



class Multiply_Command: public Binary_Command {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack		Reference to the stack of integers
	 */
	Multiply_Command(Stack<int>& stack);

	/// Multiply the left and right operators
	int do_operation(int left, int right);
};


#endif	/* Multiply Command Header Included */