//==============================================================================
/**
 * @file       Abstract_Expr_Factory.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef ABSTRACT_EXPR_FACTORY
#define ABSTRACT_EXPR_FACTORY

#include <Stack.h>
#include <string>

#include <Number_Command.h>
#include <Variable_Command.h>
#include <Add_Command.h>
#include <Subtract_Command.h>
#include <Multiply_Command.h>
#include <Divide_Command.h>
#include <Modulus_Command.h>


/**
 * @class Abstract_Expr_Factory
 *
 * Abstract factory for creating command expressions.
 *
 * All heap-allocated objects are freed either by calling release_products()
 * or automatically when the factory is destructed. Using pointers after this
 * time results in undefined behavior.
 */
class Abstract_Expr_Factory {

public:

	/// Destructor
	virtual ~Abstract_Expr_Factory() = default;

	/// Release any dynamically constructed objects from memory.
	/// It is up to the factory implementation to define how this works.
	virtual void release_products() = 0;

	/**
	 * Create a new number command
	 * @param[in]	number		The number value for this command
	 */
	virtual Number_Command* construct_number_command(int number) = 0;

	/**
	 * Construct a variable command
	 *
	 * @param[in]	name			Name of the variable
	 * @param[in]	default_value	Initial value for the variable
	 */
	virtual Variable_Command* construct_variable_command(const std::string& name, int default_value = 0) = 0;

	/// Create a new addition command
	virtual Add_Command* construct_add_command() = 0;

	/// Create a new subtraction command
	virtual Subtract_Command* construct_subtract_command() = 0;

	/// Create a new multiplication command
	virtual Multiply_Command* construct_multiply_command() = 0;

	/// Create a new divide command
	virtual Divide_Command* construct_divide_command() = 0;

	/// Create a new modulus command
	virtual Modulus_Command* construct_modulus_command() = 0;
};

#endif	/* Abstract Expression Factory Header Included */
