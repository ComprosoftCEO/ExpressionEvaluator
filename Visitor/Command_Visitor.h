//==============================================================================
/**
 * @file       Command_Visitor.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef COMMAND_VISITOR_HEADER
#define COMMAND_VISITOR_HEADER

//All of the concreate types
#include <Number_Command.h>
#include <Variable_Command.h>
#include <Add_Command.h>
#include <Subtract_Command.h>
#include <Multiply_Command.h>
#include <Divide_Command.h>
#include <Modulus_Command.h>
#include <Negate_Command.h>
#include <Square_Root_Command.h>


class Command_Visitor {

public:
	/// Destructor
	virtual ~Command_Visitor() = default;

	/// All of the concrete command types that can be visited
	virtual void visit_number_command(const Number_Command& command) = 0;
	virtual void visit_variable_command(const Variable_Command& command) = 0;
	virtual void visit_add_command(const Add_Command& command) = 0;
	virtual void visit_subtract_command(const Subtract_Command& command) = 0;
	virtual void visit_multiply_command(const Multiply_Command& command) = 0;
	virtual void visit_divide_command(const Divide_Command& command) = 0;
	virtual void visit_modulus_command(const Modulus_Command& command) = 0;
	virtual void visit_negate_command(const Negate_Command& command) = 0;
	virtual void visit_square_root_command(const Square_Root_Command& command) = 0;
};


#endif	/* Command Visitor Header Included */
