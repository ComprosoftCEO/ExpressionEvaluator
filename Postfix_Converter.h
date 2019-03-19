//==============================================================================
/**
 * @file       Postfix_Converter.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef POSTFIX_CONVERTER_HEADER
#define POSTFIX_CONVERTER_HEADER

#include <string>
#include <exception>

#include <Abstract_Expr_Factory.h>
#include <Command.h>
#include <Queue.h>
#include <Array.h>


class Postfix_Converter {

public:

	/**
	 * @class mismatched_parenthesis_exception
	 *
	 * Thrown whenever parenthesis are mismatched in the expression
	 */
	class mismatched_parenthesis_exception: public std::exception {
		const char* what() const noexcept {
			return "Mismatched parenthesis!";
		}
	};

	/**
	 * @class invalid_operator_exception
	 *
	 * Thrown whenever an unknown operator is given in an expression
	 */
	class invalid_operator_exception: public std::exception {

	private:
		std::string oper;

	public:
		invalid_operator_exception(const std::string& oper):
			oper("Invalid Operator '"+oper+"'!") {}

		const char* what() const noexcept {
			return oper.c_str();
		}
	};


public:

	/**
	 * Constructor
	 * @param[in]	factory		Factory to use to build the expression
	 */
	Postfix_Converter(Abstract_Expr_Factory& factory);

	/// Destructor
	~Postfix_Converter();

	/**
	 * Convert a tokenized infix expression to postfix. The pointers in the 
	 * returned queue are automatically freed when the postfix converter goes
	 * out of scope or a new expression is converted using the same object.
	 *
	 * @param[in]	input		List of tokens
	 */
	Queue<Command*> convert_to_postfix(Queue<std::string> input);


private:

	/**
	 * Do the logic for a single token
	 * @param[in]	token		The token to process
	 */
	void process_single_token(const std::string& token);

	/**
	 * Add a number to the current expression
	 * @param[in]	token		The string to convert to a number and add to the expression
	 */
	void add_number_to_expression(const std::string& token);

	/**
	 * Add an operator to the current expression
	 * @param[in]	token		The string to convert to an operator and add to the expression
	 * @throws		invalid_operator_exception		Unknown operator
	 */
	void add_operator_to_expression(const std::string& token);

	/**
	 * Use the factory method pattern to return a binary operator command
	 *
	 * @param[in]	input		The string to convert to a binary operator
	 * @return		The associated binary operator
	 * @throws		invalid_operator_exception		Unknown operator
	 */
	Binary_Command* get_binary_command(const std::string& input);

	/**
	 * Pop operators from the stack until the matching left parenthesis is found
	 *
	 * @param[in]	token		The right parenthesis to match with the 
	 * @throws		mismatched_parenthesis_exception	Invalid parenthesis
	 * @throws		invalid_operator_exception		Unknown operator
	 */
	void pop_until_matching_parenthesis(const std::string& right_paren);

	/**
	 * Pop any additional operators from the stack and add them to the expression
	 *
	 * @throws		mismatched_parenthesis_exception	Invalid parenthesis
	 * @throws		invalid_operator_exception		Unknown operator
	 */
	void pop_remaining_operators();

	/// Free any existing commands allocated in memory
	void free_allocated_commands();




	/**
	 * Test if the given string is a valid number
	 *
	 * @param[in]	input		The string to test
	 * @retval		true		Yes, it is a number
	 * @retval		false		No, it isn't a number
	 */
	static bool is_number(const std::string& token);

	/**
	 * Test if the given string is a valid left parenthesis token
	 *
	 * @param[in]	input		The string to test
	 * @retval		true		Yes, it is a left parenthesis token
	 * @retval		false		No, it isn't a left parenthesis token
	 */
	static bool is_left_parenthesis(const std::string& token);

	/**
	 * Test if the given string is a valid right parenthesis token
	 *
	 * @param[in]	input		The string to test
	 * @retval		true		Yes, it is a right parenthesis token
	 * @retval		false		No, it isn't a right parenthesis token
	 */
	static bool is_right_parenthesis(const std::string& token);

	/**
	 * Test if the left token and right token are matching parenthesis
	 *
	 * @param[in]	left		The left parenthesis token
	 * @param[in]	right		The right parenthesis token
	 * @retval		true		Yes, the two parenthesis match
	 * @retval		false		No, the two parenthesis don't match
	 */
	static bool is_matching_parenthesis(const std::string& left, const std::string& right);

	/**
	 * Get a numeric operator precedence for the token, following PEMDAS rules.
	 * A higher number means that an operator has a higher precedence.
	 *
	 * @param[in]	token		The string to get the precedence for
	 * @return		Precedence
	 * @throws		invalid_operator_exception		Unknown operator
	 */
	static int get_operator_precedence(const std::string& token);


private:

	/// The factory to use when converting to postfix
	Abstract_Expr_Factory& factory;

	/// Temporary stack of operators used while converting
	Stack<std::string> stack;

	/// Final expression
	Queue<Command*> expression;
};


#endif	/* Postfix Converter Header Included */
