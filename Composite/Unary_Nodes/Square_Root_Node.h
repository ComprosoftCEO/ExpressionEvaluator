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
#include <exception>



class Square_Root_Node: public Unary_Node {

public:

	/**
	 * Initializing Constructor
	 *
	 * @param[in]		child_expr		Child expression tree for this operator
	 */
	Square_Root_Node(Expr_Node* child_expr = nullptr);

	/// Find the square root
	int do_operation(int input);


	/**
	 * @class negative_square_root_exception
	 * Thrown when trying to do the square root of a negative number
	 */
	class negative_square_root_exception: public std::exception {
		const char* what() const noexcept {
			return "Trying to square root a negative number!";
		}
	};
};


#endif	/* Square Root Node Header Included */
