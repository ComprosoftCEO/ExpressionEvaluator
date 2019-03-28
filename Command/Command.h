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
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		stack		Reference to the stack of integers
	 */
	Command(Stack<int>& stack, int precedence = 0);

	/**
	 * Get the numeric precedence for this command
	 * @return			precedence
	 */
	int get_precedence() const;

	/// Destructor
	virtual ~Command();

	/// Run the command for this object
	virtual void execute(void) = 0;

protected:
	/// Stack of integers used to evaluate a whole expression
	Stack<int>& stack;

	/// Precedence for this command
	int precedence;
};


#endif	/* Command Header Included */
