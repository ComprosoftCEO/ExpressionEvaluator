//==============================================================================
/**
 * @file       Command_Visitor.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef COMMAND_VISITOR_HEADER
#define COMMAND_VISITOR_HEADER

// Forward declare all of the concrete class types
class Number_Command;
class Variable_Command;
class Add_Command;
class Subtract_Command;
class Multiply_Command;
class Divide_Command;
class Modulus_Command;
class Negate_Command;
class Square_Root_Command;

class Command_Visitor {

public:
  /// Destructor
  virtual ~Command_Visitor() = default;

  /// All of the concrete command types that can be visited
  virtual void visit_number_command(Number_Command& command)           = 0;
  virtual void visit_variable_command(Variable_Command& command)       = 0;
  virtual void visit_add_command(Add_Command& command)                 = 0;
  virtual void visit_subtract_command(Subtract_Command& command)       = 0;
  virtual void visit_multiply_command(Multiply_Command& command)       = 0;
  virtual void visit_divide_command(Divide_Command& command)           = 0;
  virtual void visit_modulus_command(Modulus_Command& command)         = 0;
  virtual void visit_negate_command(Negate_Command& command)           = 0;
  virtual void visit_square_root_command(Square_Root_Command& command) = 0;
};

#endif /* Command Visitor Header Included */
