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

// Forward declare all of the concreate types
class Number_Node;
class Variable_Node;
class Add_Node;
class Subtract_Node;
class Multiply_Node;
class Divide_Node;
class Modulus_Node;
class Negate_Node;
class Square_Root_Node;

class Expr_Node_Visitor {

public:
  /// Destructor
  virtual ~Expr_Node_Visitor() = default;

  /// All of the concrete node types that can be visited
  virtual void visit_number_node(Number_Node& node)           = 0;
  virtual void visit_variable_node(Variable_Node& node)       = 0;
  virtual void visit_add_node(Add_Node& node)                 = 0;
  virtual void visit_subtract_node(Subtract_Node& node)       = 0;
  virtual void visit_multiply_node(Multiply_Node& node)       = 0;
  virtual void visit_divide_node(Divide_Node& node)           = 0;
  virtual void visit_modulus_node(Modulus_Node& node)         = 0;
  virtual void visit_negate_node(Negate_Node& node)           = 0;
  virtual void visit_square_root_node(Square_Root_Node& node) = 0;
};

#endif /* Expression Node Visitor Header Included */
