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

//Forward declare all of the concrete class types
class Number_Command;
class Variable_Command;
class Add_Command;
class Subtract_Command;
class Multiply_Command;
class Divide_Command;
class Modulus_Command;
class Negate_Command;
class Square_Root_Command;


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
