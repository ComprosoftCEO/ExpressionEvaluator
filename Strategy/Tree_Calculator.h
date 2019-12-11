//==============================================================================
/**
 * @file       Tree_Calculator.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef TREE_CALCULATOR_HEADER
#define TREE_CALCULATOR_HEADER

#include "Calculator.h"

#include <Tree_Builder.h>

class Tree_Calculator: public Calculator {

public:
  /// Default constructor
  Tree_Calculator();

private:
  /// Builder used to create the postfix expression
  Tree_Builder tree_builder;
};

#endif /* Tree Calculator Header Included */
