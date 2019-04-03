//==============================================================================
/**
 * @file       Binary_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef BINARY_NODE_HEADER
#define BINARY_NODE_HEADER

#include "Operator_Node.h"


/**
 * @class Binary_Node
 *
 * Represents a binary operator in the expression tree. When destructed,
 * each sub expression tree from the constructor will be deleted.
 */
class Binary_Node: public Operator_Node {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		precedence		Precedence for this operator
	 * @param[in]		left_expr		Left expression tree for this operator
	 * @param[in]		right_expr		Right expression tree for this operator
	 */
	Binary_Node(int precedence, Expr_Node* left_expr, Expr_Node* right_expr);

	/// Destructor
	/// Deletes left_expr and right_expr (passed in the constructor)
	virtual ~Binary_Node();

	/// Return the result of this binary command
	int eval();

	/**
	 * Execute the binary operation on the given input
	 *
	 * @param			left		Left hand side of the binary function
	 * @param			right		Right hand side of the binary function
	 * @return			Result of the binary function
	 */
	virtual int do_operation(int left, int right) = 0;

private:
	/// Left expression in the expression tree
	Expr_Node* left_expr_;

	/// Right expression in the expression tree
	Expr_Node* right_expr_;
};



#endif	/* Binary Node Header Included */
