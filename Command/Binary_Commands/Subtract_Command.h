//==============================================================================
/**
 * @file       Subtract_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef SUBTRACT_COMMAND_HEADER
#define SUBTRACT_COMMAND_HEADER

#include "../Binary_Command.h"



class Subtract_Command: public Binary_Command {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack		Reference to the stack of integers
	 */
	Subtract_Command(Stack<int>& stack);

	/// Subtract the left and right operators
	int do_operation(int left, int right);
};


#endif	/* Subtract Command Header Included */
