//==============================================================================
/**
 * @file       Divide_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef DIVIDE_NODE_HEADER
#define DIVIDE_NODE_HEADER

#include "../Binary_Node.h"

class Divide_Node: public Binary_Node {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		left_expr		Left expression tree for this operator
	 * @param[in]		right_expr		Right expression tree for this operator
	 */
	Divide_Node(Expr_Node* left_expr, Expr_Node* right_expr);

	/// Divide the left and right operators
	int do_operation(int left, int right);
};


#endif	/* Divide Node Header Included */
