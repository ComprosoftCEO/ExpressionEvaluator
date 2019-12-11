// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment
#include "Expr_Evaluator.h"

// Expr_Node headers
#include <Add_Node.h>
#include <Divide_Node.h>
#include <Modulus_Node.h>
#include <Multiply_Node.h>
#include <Negate_Node.h>
#include <Number_Node.h>
#include <Square_Root_Node.h>
#include <Subtract_Node.h>
#include <Variable_Node.h>

//
// Visit the number
//
void Expr_Evaluator::visit_number_node(Number_Node& node) {
  this->stack_.push(node.get_value());
}

//
// Visit the variable
//
void Expr_Evaluator::visit_variable_node(Variable_Node& node) {
  this->stack_.push(node.get_value());
}

//
// Visit the binary nodes
//
void Expr_Evaluator::visit_add_node(Add_Node& node) {
  this->do_binary_node(node);
}

void Expr_Evaluator::visit_subtract_node(Subtract_Node& node) {
  this->do_binary_node(node);
}

void Expr_Evaluator::visit_multiply_node(Multiply_Node& node) {
  this->do_binary_node(node);
}

void Expr_Evaluator::visit_divide_node(Divide_Node& node) {
  this->do_binary_node(node);
}

void Expr_Evaluator::visit_modulus_node(Modulus_Node& node) {
  this->do_binary_node(node);
}

//
// Visit the unary nodes
//
void Expr_Evaluator::visit_negate_node(Negate_Node& node) {
  this->do_unary_node(node);
}

void Expr_Evaluator::visit_square_root_node(Square_Root_Node& node) {
  this->do_unary_node(node);
}

//
// Process a binary node
//
void Expr_Evaluator::do_binary_node(Binary_Node& node) {

  // Evaluate the left and right nodes first
  node.get_left_expression()->accept(*this);
  node.get_right_expression()->accept(*this);

  // Pop values off stack in reverse order, then push
  int first, second;
  second = this->stack_.pop();
  first  = this->stack_.pop();

  // Run the stored binary method
  int result = node.do_operation(first, second);

  // Push the result back onto the stack
  this->stack_.push(result);
}

//
// Process a unary node
//
void Expr_Evaluator::do_unary_node(Unary_Node& node) {

  // Evaluate the child expression first
  node.get_child_expression()->accept(*this);

  // Pop 1 number off the stack
  int val = this->stack_.pop();

  // Run the unary operation
  val = node.do_operation(val);

  // Push the result back onto the stack
  this->stack_.push(val);
}
