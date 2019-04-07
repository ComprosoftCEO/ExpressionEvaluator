//==============================================================================
/**
 * @file       Number_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef NUMBER_NODE_HEADER
#define NUMBER_NODE_HEADER

#include "Expr_Node.h"

/**
 * @class Number_Node
 *
 * Represents a number in the expression tree
 */
class Number_Node: public Expr_Node {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		value		Value stored inside this number
	 */
	Number_Node(int value);

	/// Return the stored value from this number
	int evaluate();

	/// Accept the visitor
	void accept(Expr_Node_Visitor& v);

private:
	int value_;
};


#endif	/* Numbrer Node Header Included */
