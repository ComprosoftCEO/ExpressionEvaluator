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

//Forward declare the visitor class to avoid circular reference
class Expr_Node_Visitor;


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
	virtual int evaluate() = 0;

	/**
	 * Accept the expression visitor for this object
	 * @param		visitor			The visitor
	 */
	virtual void accept(Expr_Node_Visitor& v) = 0;
};


#endif	 /* Expression Node Header Included */
