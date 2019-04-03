//==============================================================================
/**
 * @file       Operator_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef OPERATOR_COMMAND_HEADER
#define OPERATOR_COMMAND_HEADER

#include "Command.h"

/**
 * @class Operator_Command
 *
 * Represents a generic operator command that can occur on an expression.
 * All operators have a precedence.
 */
class Operator_Command: public Command {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack			Reference to the stack of integers
	 * @param[in]		precedence		Precedence for this operator
	 */
	Operator_Command(Stack<int>& stack, int precedence);

	/**
	 * Get the precedence for this operator
	 * @return			Precedence
	 */
	int get_precedence() const;

private:
	/// Operator precedence
	int precedence_;

};


//Include inline files
#include "Operator_Command.inl"


#endif	/* Operator Command Header Included */
