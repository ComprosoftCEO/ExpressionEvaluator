//==============================================================================
/**
 * @file       Number_Command.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef NUMBER_COMMAND_HEADER
#define NUMBER_COMMAND_HEADER

#include "Command.h"

/**
 * @class Number_Command
 *
 * Add a number onto the stack
 */
class Number_Command: public Command {

public:
  /**
   * Initializing Constructor
   *
   * @param[in]		number		The number to store
   */
  Number_Command(int number);

  /// Push a number onto the stack
  void execute(Stack<int>& stack);

  /// Accept the visitor
  void accept(Command_Visitor& v);

private:
  /// Number stored to push onto the stack
  int number_;
};

#endif /* Number Command Header Included */
