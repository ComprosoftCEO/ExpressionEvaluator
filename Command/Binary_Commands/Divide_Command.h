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
};


#endif	/* Divide Command Header Included */
