//==============================================================================
/**
 * @file       Postfix_Calculator.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef POSTFIX_CALCULATOR_HEADER
#define POSTFIX_CALCULATOR_HEADER

#include "Calculator.h"

#include <Postfix_Builder.h>

class Postfix_Calculator: public Calculator {

public:
  /// Default constructor
  Postfix_Calculator();

private:
  /// Builder used to create the postfix expression
  Postfix_Builder postfix_builder;
};

#endif /* Postfix Calculator Header Included */
