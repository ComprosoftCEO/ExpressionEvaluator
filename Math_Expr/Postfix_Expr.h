//==============================================================================
/**
 * @file       Postfix_Expr.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef POSTFIX_EXPR_HEADER
#define POSTFIX_EXPR_HEADER

#include "Math_Expr.h"

#include <Array.h>
#include <Command.h>
#include <Stack.h>

/**
 * @class Postfix_Expr
 *
 * Stores the expression as an array of commands to execute. Since the
 * commands are constructed from a factory, this class is not responsible
 * for freeing the commands.
 */
class Postfix_Expr: public Math_Expr {

public:
  /// Evaluate the postfix expression
  int evaluate();

  /**
   * Add a command into the expression to evaluate
   *
   * @param[in]		command			The command to add to the expression
   */
  void add_command(Command* command);

  /**
   * Add all of the commands from the sub expression onto the current expression.
   * @param[in]		expr			Expression object to copy the commands from
   */
  void append_sub_expression(const Postfix_Expr& expr);

  /**
   * Get all of the variables and their values from this expression
   * @return		Map with all variables and their associated values
   */
  std::map<std::string, int> get_variable_values();

  /**
   * Set all variable values in the expression. If a variable is not
   * defined in the map, then its value will remain unchanged from
   * the default or existing value.
   *
   * @param[in]	values		Lookup table of values for the variables
   */
  void set_variable_values(const std::map<std::string, int>& values);

private:
  /// Array of commands to run
  Array<Command*> to_run_;

  /// Stack of integers used during evaluation
  Stack<int> stack_;
};

#endif /* Postfix Expression Header Included */
