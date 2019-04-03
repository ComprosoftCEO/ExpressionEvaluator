//==============================================================================
/**
 * @file       Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef COMMAND_HEADER
#define COMMAND_HEADER

#include <Stack.h>



/**
 * @class Command
 *
 * Abstract class to represent a command that can occur on an expression
 */
class Command {

public:
	/// Destructor
	virtual ~Command() = default;

	/**
	 * Run the command for this object
	 *
	 * @param[in,out]		stack			Reference to the stack of integers
	 */
	virtual void execute(Stack<int>& stack) = 0;
};


#endif	/* Command Header Included */
