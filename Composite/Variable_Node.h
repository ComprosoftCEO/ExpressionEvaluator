//==============================================================================
/**
 * @file       Variable_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef VARIABLE_NODE_HEADER
#define VARIABLE_NODE_HEADER

#include "Expr_Node.h"
#include <string>


/**
 * @class Variable_Node
 *
 * Represents a number placeholder in the expression tree
 */
class Variable_Node: public Expr_Node {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		name			Name of this variable
	 * @param[in]		default_value	Default integer value for this variable
	 */
	Variable_Node(const std::string& name, int default_value = 0);

	/// Returned the current variable value
	int evaluate();

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
	void accept(Expr_Node_Visitor& v);

private:
	/// Name of the variable
	std::string name_;

	/// Current integer value of the variable
	int value_;
};

//Include the inline functions
#include "Variable_Node.inl"


#endif	/* Variable Node Header Included */
