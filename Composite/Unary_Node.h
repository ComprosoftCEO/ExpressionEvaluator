//==============================================================================
/**
 * @file       Unary_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef UNARY_NODE_HEADER
#define UNARY_NODE_HEADER

#include "Operator_Node.h"


/**
 * @class Unary_Node
 *
 * Represents a unary operator in the expression tree. When destructed,
 * the child sub expression tree from the constructor will be deleted.
 */
class Unary_Node: public Operator_Node {

public:
	/**
	 * Initializing Constructor
	 *
	 * @param[in]		precedence		Precedence for this operator
	 * @param[in]		child_expr		Child expression tree for this operator
	 */
	Unary_Node(int precedence, Expr_Node* child_expr);

	/// Destructor
	/// Deletes child_expr (passed in the constructor)
	virtual ~Unary_Node();

	/// Return the result of this unary command
	int evaluate();

	/**
	 * Execute the unary operation on the given input
	 *
	 * @param			input		Input to the unary function
	 * @return			Result of the unary function
	 */
	virtual int do_operation(int input) = 0;

	/**
	 * Sets the children (if any) of this operator object, popping off
	 * from the stack in reverse order of the children. Existing children
	 * are automatically deleted.
	 *
	 * @param[in]		stack				Stack to pop for children
	 * @exception		empty_exception		The stack is empty.
	 */
	void load_children_from_stack(Stack<Expr_Node*>& stack);

private:
	/// Child expression in the expression tree
	Expr_Node* child_expr_;
};



#endif	/* Unary Node Header Included */
