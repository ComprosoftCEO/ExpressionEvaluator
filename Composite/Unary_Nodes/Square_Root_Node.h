//==============================================================================
/**
 * @file       Square_Root_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef SQUARE_ROOT_NODE_HEADER
#define SQUARE_ROOT_NODE_HEADER

#include "../Unary_Node.h"


class Square_Root_Node: public Unary_Node {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		child_expr		Child expression tree for this operator
	 */
	Square_Root_Node(Expr_Node* child_expr);

	/// Find the square root
	int do_operation(int input);

};


#endif	/* Square Root Node Header Included */
