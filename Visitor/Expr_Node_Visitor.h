//==============================================================================
/**
 * @file       Expr_Node_Visitor.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef EXPRESSION_NODE_VISITOR_HEADER
#define EXPRESSION_NODE_VISITOR_HEADER

//All of the concreate types
#include <Number_Node.h>
#include <Variable_Node.h>
#include <Add_Node.h>
#include <Subtract_Node.h>
#include <Multiply_Node.h>
#include <Divide_Node.h>
#include <Modulus_Node.h>
#include <Negate_Node.h>
#include <Square_Root_Node.h>


class Expr_Node_Visitor {

public:
	/// Destructor
	virtual ~Expr_Node_Visitor() = default;

	/// All of the concrete node types that can be visited
	virtual void visit_number_node(const Number_Node& node) = 0;
	virtual void visit_variable_node(const Variable_Node& node) = 0;
	virtual void visit_add_node(const Add_Node& node) = 0;
	virtual void visit_subtract_node(const Subtract_Node& node) = 0;
	virtual void visit_multiply_node(const Multiply_Node& node) = 0;
	virtual void visit_divide_node(const Divide_Node& node) = 0;
	virtual void visit_modulus_node(const Modulus_Node& node) = 0;
	virtual void visit_negate_node(const Negate_Node& node) = 0;
	virtual void visit_square_root_node(const Square_Root_Node& node) = 0;
};


#endif	/* Expression Node Visitor Header Included */
