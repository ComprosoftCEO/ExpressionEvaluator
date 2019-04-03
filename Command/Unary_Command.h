//==============================================================================
/**
 * @file       Unary_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef UNARY_COMMAND_HEADER
#define UNARY_COMMAND_HEADER

#include "Operator_Command.h"

/**
 * @class Unary_Command
 *
 * Abstract template method class for executing a unary operation on an integer
 */
class Unary_Command: public Operator_Command {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack			Reference to the stack of integers
	 * @param[in]		precedence		Precedence for this operator
	 */
	Unary_Command(Stack<int>& stack, int precedence);

	/// Run a unary function on the stack
	void execute(void);

	/**
	 * Execute the unary operation on the given input
	 *
	 * @param			input		Input to the unary function
	 * @return			Result of the unary function
	 */
	virtual int do_operation(int input) = 0;
};




#endif	/* Unary Command Header Included */
