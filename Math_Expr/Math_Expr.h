//==============================================================================
/**
 * @file       Math_Expr.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef MATH_EXPR_HEADER
#define MATH_EXPR_HEADER


class Math_Expr {

public:
	/// Destructor
	virtual ~Math_Expr() = default;

	/**
	 * Evaluate the math expression
	 * @return		Result of the math expression
	 */
	virtual int evaluate() = 0;

};


#endif	/* Math Expression Header Included */
