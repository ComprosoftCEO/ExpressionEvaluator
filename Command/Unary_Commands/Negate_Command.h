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

	/// Default constructor
	Negate_Command();

	/// Multiply input by -1
	int do_operation(int input);

	/// Accept the visitor
	void accept(Command_Visitor& v);
};


#endif	/* Negate Command Header Included */
