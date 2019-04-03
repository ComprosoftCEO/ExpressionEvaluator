//==============================================================================
/**
 * @file       Tree_Expr.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef TREE_EXPR_HEADER
#define TREE_EXPR_HEADER

#include "Math_Expr.h"
#include <Expr_Node.h>


class Tree_Expr: public Math_Expr {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		root		Root node for this expression tree
	 */
	Tree_Expr(Expr_Node* root);

	/// Destruct this expression tree math expression.
	/// Since the tree owns the root node, it is deleted in this method.
	~Tree_Expr();

	/// Evaluate the expression tree
	int evaluate();


private:
	/// The root of the expression tree
	Expr_Node* root_;
};


#endif	/* Tree Expression Header Included */
