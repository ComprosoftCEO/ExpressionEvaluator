//==============================================================================
/**
 * @file       Binary_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef BINARY_NODE_HEADER
#define BINARY_NODE_HEADER

#include "Operator_Node.h"


/**
 * @class Binary_Node
 *
 * Represents a binary operator in the expression tree. When destructed,
 * each sub expression tree from the constructor will be deleted.
 */
class Binary_Node: public Operator_Node {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		precedence		Precedence for this operator
	 * @param[in]		left_expr		Left expression tree for this operator
	 * @param[in]		right_expr		Right expression tree for this operator
	 */
	Binary_Node(int precedence, Expr_Node* left_expr, Expr_Node* right_expr);

	/// Destructor
	/// Deletes left_expr and right_expr (passed in the constructor)
	virtual ~Binary_Node();

	/// Return the result of this binary command
	int evaluate();

	/**
	 * Execute the binary operation on the given input
	 *
	 * @param			left		Left hand side of the binary function
	 * @param			right		Right hand side of the binary function
	 * @return			Result of the binary function
	 */
	virtual int do_operation(int left, int right) = 0;

	/**
	 * Sets the children (if any) of this operator object, popping off
	 * from the stack in reverse order of the children. Existing children
	 * are automatically deleted.
	 *
	 * @param[in]		stack				Stack to pop for children
	 * @exception		empty_exception		The stack is empty.
	 */
	void load_children_from_stack(Stack<Expr_Node*>& stack);

	/**
	 * Get the stored left expression
	 * @return			Left expression
	 */
	Expr_Node* get_left_expression() const;

	/**
	 * Get the stored right expression
	 * @return			Right expression
	 */
	Expr_Node* get_right_expression() const;

private:
	/// Left expression in the expression tree
	Expr_Node* left_expr_;

	/// Right expression in the expression tree
	Expr_Node* right_expr_;
};


//Include the inline functions
#include "Binary_Node.inl"


#endif	/* Binary Node Header Included */
