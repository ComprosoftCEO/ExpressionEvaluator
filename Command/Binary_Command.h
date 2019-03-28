//==============================================================================
/**
 * @file       Binary_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef BINARY_COMMAND_HEADER
#define BINARY_COMMAND_HEADER

#include "Command.h"

/**
 * @class Binary_Command
 *
 * Abstract template method class for executing a binary operation on an integer
 */
class Binary_Command: public Command {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack		Reference to the stack of integers
	 */
	Binary_Command(Stack<int>& stack, int precedence = 0);

	/// Run a binary function on the stack
	void execute(void);

	/**
	 * Execute the binary operation on the given input
	 *
	 * @param			left		Left hand side of the binary function
	 * @param			right		Right hand side of the binary function
	 * @return			Result of the binary function
	 */
	virtual int do_operation(int left, int right) = 0;
};



#endif	/* Binary Command Header Included */
