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

	/// Default constructor
	Subtract_Command();

	/// Subtract the left and right operators
	int do_operation(int left, int right);

	/// Accept the visitor
	void accept(Command_Visitor& v);
};


#endif	/* Subtract Command Header Included */
