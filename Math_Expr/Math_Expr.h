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

#include <map>

/**
 * @class Math_Expr
 *
 * Interface for a generic math expresison in memory, along with several
 * methods to work with the expression.
 */
class Math_Expr {

public:
  /// Destructor
  virtual ~Math_Expr() = default;

  /**
   * Evaluate the math expression
   * @return		Result of the math expression
   */
  virtual int evaluate() = 0;

  /**
   * Get all of the variables and their values from this expression
   * @return		Map with all variables and their associated values
   */
  virtual std::map<std::string, int> get_variable_values() = 0;

  /**
   * Set all variable values in the expression. If a variable is not
   * defined in the map, then its value will remain unchanged from
   * the default or existing value.
   *
   * @param[in]	values		Lookup table of values for the variables
   */
  virtual void set_variable_values(const std::map<std::string, int>& values) = 0;
};

#endif /* Math Expression Header Included */
