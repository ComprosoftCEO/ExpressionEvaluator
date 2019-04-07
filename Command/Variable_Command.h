//==============================================================================
/**
 * @file       Variable_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef VARIABLE_COMMAND_HEADER
#define VARIABLE_COMMAND_HEADER

#include "Command.h"
#include <string>


/**
 * @class Variable_Command
 *
 * Represents a placeholder for a number
 */
class Variable_Command: public Command {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		name			Name of this variable
	 * @param[in]		default_value	Default integer value for this variable
	 */
	Variable_Command(const std::string& name, int default_value = 0);

	/// Push the variable value onto the stack
	void execute(Stack<int>& stack);

	/**
	 * Get the string name of this variable
	 * @return			Name of this variable
	 */
	const std::string& get_name() const;

	/**
	 * Get the current value of this variable
	 * @return			Current variable value
	 */
	int get_value() const;

	/**
	 * Set a new integer value for this variable
	 * @param[in]		new_value		New value for the variable
	 */
	void set_value(int new_value);

	/// Accept the visitor
	void accept(Command_Visitor& v);

private:
	/// Name of the variable
	std::string name_;

	/// Current integer value of the variable
	int value_;
};


//Include the inline functions
#include "Variable_Command.inl"

#endif	/* Variable Command Header Included */
