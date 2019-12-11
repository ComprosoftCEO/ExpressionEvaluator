//==============================================================================
/**
 * @file       Calculator.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef CALCULATOR_HEADER
#define CALCULATOR_HEADER

#include <Expr_Builder.h>
#include <string>

/**
 * @class Calculator
 *
 * Abstract class that can parse an infix expression. Must be extended by
 * a concrete Calculator class to work properly.
 */
class Calculator {

public:
  /// Destructor
  virtual ~Calculator() = default;

  /**
   * Convert a tokenized infix expression to postfix. The returned
   * pointer does not need to be freed.
   *
   * @param[in]		input		List of tokens
   * @return			Parsed expression
   * @throws			Subclass of std::exception if the parse is invalid
   */
  Math_Expr* parse_infix_expression(const std::string& input);

  /// Release any previously constructed expressions from memory
  void release_expressions();

  /// Get a reference to the underlying builder used to construct this
  ///  expression.
  Expr_Builder& get_builder();

protected:
  /**
   * Constructor
   * @param[in]		builder		Builder to construct the underlying expression
   */
  Calculator(Expr_Builder& builder);

private:
  /**
   * Do the logic for a single token
   * @param[in]	token		The token to process
   */
  void process_single_token(const std::string& token);

  /**
   * Test if the given string is a valid number
   *
   * @param[in]	input		The string to test
   * @retval		true		Yes, it is a number
   * @retval		false		No, it isn't a number
   */
  static bool is_number(const std::string& token);

  /**
   * Test if the given string is a valid variable identifier.
   * Variables are any combination of letters (a-z and A-Z).
   *
   * @param[in]	input		The string to test
   * @retval		true		Yes, it is a variable
   * @retval		false		No, it isn't a variable
   */
  static bool is_variable(const std::string& token);

private:
  /// Builder used to construct the expression
  Expr_Builder& builder;
};

#endif /* Calculator Header Included */
