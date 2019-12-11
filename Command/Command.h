//==============================================================================
/**
 * @file       Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef COMMAND_HEADER
#define COMMAND_HEADER

#include <Stack.h>

// Forward declare the visitor (to avoid a circular reference)
class Command_Visitor;

/**
 * @class Command
 *
 * Abstract class to represent a command that can occur on an expression
 */
class Command {

public:
  /// Destructor
  virtual ~Command() = default;

  /**
   * Run the command for this object
   *
   * @param[in,out]		stack			Reference to the stack of integers
   */
  virtual void execute(Stack<int>& stack) = 0;

  /**
   * Accept the expression visitor for this object
   * @param		visitor			The visitor
   */
  virtual void accept(Command_Visitor& v) = 0;
};

#endif /* Command Header Included */
