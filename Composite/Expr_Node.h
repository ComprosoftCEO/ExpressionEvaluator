//==============================================================================
/**
 * @file       Expr_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef EXPR_NODE_HEADER
#define EXPR_NODE_HEADER



/**
 * @class Expr_Node
 *
 * Abstract class to represent a generic node in an expression tree.
 */
class Expr_Node {

public:
	/// Destructor
	virtual ~Expr_Node() = default;

	/**
	 * Evaluate this expression tree
	 * @return		Result of the evaluation	
	 */
	virtual int eval() = 0;

};


#endif	 /* Expression Node Header Included */
