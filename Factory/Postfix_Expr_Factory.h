//==============================================================================
/**
 * @file       Postfix_Expr_Factory.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef POSTFIX_EXPR_FACTORY
#define POSTFIX_EXPR_FACTORY

#include "Abstract_Expr_Factory.h"



class Postfix_Expr_Factory: public Abstract_Expr_Factory {

public:

	/**
	 * Constructor
	 * @param[in]	stack		Stack to store the evaluated expression
	 */
	Postfix_Expr_Factory(Stack<int>& stack);

	/** Create a new number command
	 * @param[in]	number		The number for this point
	 */
	Number_Command* construct_number_command(int number);

	/// Create a new addition command
	Add_Command* construct_add_command();

	/// Create a new subtraction command
	Subtract_Command* construct_subtract_command();

	/// Create a new multiplication command
	Multiply_Command* construct_multiply_command();

	/// Create a new divide command
	Divide_Command* construct_divide_command();

	/// Create a new modulus command
	Modulus_Command* construct_modulus_command();
};



#endif	/* Postfix Expression Factory Included */
