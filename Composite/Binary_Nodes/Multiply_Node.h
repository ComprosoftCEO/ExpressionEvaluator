//==============================================================================
/**
 * @file       Multiply_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef MULTIPLY_NODE_HEADER
#define MULTIPLY_NODE_HEADER

#include "../Binary_Node.h"

class Multiply_Node: public Binary_Node {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		left_expr		Left expression tree for this operator
	 * @param[in]		right_expr		Right expression tree for this operator
	 */
	Multiply_Node(Expr_Node* left_expr = nullptr, Expr_Node* right_expr = nullptr);

	/// Multiply the left and right operators
	int do_operation(int left, int right);
};


#endif	/* Multiply Node Header Included */
