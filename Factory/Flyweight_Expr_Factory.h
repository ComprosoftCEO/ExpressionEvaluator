//==============================================================================
/**
 * @file       Flyweight_Expr_Factory.h
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
#include <Queue.h>


class Flyweight_Expr_Factory: public Abstract_Expr_Factory {

public:

	/**
	 * Constructor
	 * @param[in]	stack		Stack to store the evaluated expression
	 */
	Flyweight_Expr_Factory(Stack<int>& stack);

	/// Destructor
	~Flyweight_Expr_Factory();

	/// Release any dynamically constructed objects from memory
	void release_products() ;

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


private:

	/// Internal, statically-allocated command objects
	Add_Command add_command;
	Subtract_Command subtract_command;
	Multiply_Command multiply_command;
	Divide_Command divide_command;
	Modulus_Command modulus_command;

	/// List of dynamically-allocated commands to free
	Queue<Command*> to_free;

};



#endif	/* Flyweight Expression Factory Included */
