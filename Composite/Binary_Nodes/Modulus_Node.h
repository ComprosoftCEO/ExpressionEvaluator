//==============================================================================
/**
 * @file       Modulus_Node.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef MODULUS_NODE_HEADER
#define MODULUS_NODE_HEADER

#include "../Binary_Node.h"

#include <exception>

class Modulus_Node: public Binary_Node {

public:
  /**
   * Initializing Constructor
   *
   * @param[in]		left_expr		Left expression tree for this operator
   * @param[in]		right_expr		Right expression tree for this operator
   */
  Modulus_Node(Expr_Node* left_expr = nullptr, Expr_Node* right_expr = nullptr);

  /// Modulus the left and right operators
  int do_operation(int left, int right);

  /// Accept the visitor
  void accept(Expr_Node_Visitor& v);

  /**
   * @class modulus_zero_exception
   * Thrown when trying to do a number modulus 0
   */
  class modulus_zero_exception: public std::exception {
    const char* what() const noexcept {
      return "Floating point exception: modulus 0!";
    }
  };
};

#endif /* Modulus Node Header Included */
