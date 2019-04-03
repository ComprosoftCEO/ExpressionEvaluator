//==============================================================================
/**
 * @file       Add_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef ADD_COMMAND_HEADER
#define ADD_COMMAND_HEADER

#include "../Binary_Command.h"



class Add_Command: public Binary_Command {

public:

	/// Default constructor
	Add_Command();

	/// Add the left and right operators
	int do_operation(int left, int right);
};


#endif	/* Add Command Header Included */
