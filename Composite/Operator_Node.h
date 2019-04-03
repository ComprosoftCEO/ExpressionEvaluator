//==============================================================================
/**
 * @file       Operator_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef OPERATOR_NODE_HEADER
#define OPERATOR_NODE_HEADER


#include "Expr_Node.h"

/**
 * @class Operator_Node
 *
 * Represents a generic operator in the expression tree
 */
class Operator_Node: public Expr_Node {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		precedence		Precedence for this operator
	 */
	Operator_Node(int precedence);

	/**
	 * Get the precedence for this operator
	 * @return			Precedence of this operator
	 */
	int get_precedence() const;

private:
	int precedence_;

};


// Include the inline file
#include "Operator_Node.inl"

#endif	/* Operator Node Header Included */
