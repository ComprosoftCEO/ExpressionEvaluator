//==============================================================================
/**
 * @file       Expr_Evaluator.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef EXPR_EVALUATOR_HEADER
#define EXPR_EVALUATOR_HEADER

#include <Expr_Node_Visitor.h>
#include <Stack.h>


//Forward declare classes
class Binary_Node;
class Unary_Node;


/**
 * @class Expr_Evaluator
 *
 * Evaluate the expression in the Expr_Node hierarchy using a stack
 * and the visitor pattern;
 */
class Expr_Evaluator: public Expr_Node_Visitor {

public:

	/// Call this method to clear the internal state before
	///  attempting to evaluate a new expression
	void reset_evaluator();

	/**
	 * Get the result of the last evaluated expression
	 * @return		Expression result
	 * @throws		empty_exception
	 */
	int get_result() const;

	/// All of the concrete node types that can be visited
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


	/// Internal stack used to evaluate the expression
	Stack<int> stack_;

}; 


//Include inline methods
#include "Expr_Evaluator.inl"

#endif	/* Expression Evaluator Header Included */
