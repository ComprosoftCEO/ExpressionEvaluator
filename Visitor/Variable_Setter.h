//==============================================================================
/**
 * @file       Variable_Setter.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef VARIABLE_SETTER_HEADER
#define VARIABLE_SETTER_HEADER

#include <Command_Visitor.h>
#include <Expr_Node_Visitor.h>
#include <map>


/**
 * @class Variable_Setter
 *
 * Class that sets all of the variables from a given expression.
 * Can be used with both the Command types and Expr_Node types.
 */
class Variable_Setter: public Command_Visitor, public Expr_Node_Visitor {

public:

	/**
	 * Initializing Constructor
	 * @param[in]		lookup		Map to look up the variable values
	 */
	Variable_Setter(const std::map<std::string, int>& lookup);

	/// Command visitor methods
	void visit_number_command(Number_Command& command);
	void visit_variable_command(Variable_Command& command);
	void visit_add_command(Add_Command& command);
	void visit_subtract_command(Subtract_Command& command);
	void visit_multiply_command(Multiply_Command& command);
	void visit_divide_command(Divide_Command& command);
	void visit_modulus_command(Modulus_Command& command);
	void visit_negate_command(Negate_Command& command);
	void visit_square_root_command(Square_Root_Command& command);

	/// Expr_Node visitor methods
	void visit_number_node(Number_Node& node);
	void visit_variable_node(Variable_Node& node);
	void visit_add_node(Add_Node& node);
	void visit_subtract_node(Subtract_Node& node);
	void visit_multiply_node(Multiply_Node& node);
	void visit_divide_node(Divide_Node& node);
	void visit_modulus_node(Modulus_Node& node);
	void visit_negate_node(Negate_Node& node);
	void visit_square_root_node(Square_Root_Node& node);


private:

	/// Treat all unary nodes uniformly when processing
	void do_unary_node(Unary_Node& node);

	/// Treat all binary nodes uniformly when processing
	void do_binary_node(Binary_Node& node);

	/// Internal stored map of variables
	const std::map<std::string, int>& lookup_;
};


#endif	/* Variable Getter Header Included */
