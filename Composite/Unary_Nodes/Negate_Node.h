//==============================================================================
/**
 * @file       Negate_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef NEGATE_NODE_HEADER
#define NEGATE_NODE_HEADER

#include "../Unary_Node.h"


class Negate_Node: public Unary_Node {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		child_expr		Child expression tree for this operator
	 */
	Negate_Node(Expr_Node* child_expr);

	/// Multiply input by -1
	int do_operation(int input);

};


#endif	/* Negate Node Header Included */
