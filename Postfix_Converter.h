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

	/**
	 * @class invalid_infix_exception
	 *
	 * Thrown whenever the order of numbers and operators is invalid
	 */
	class invalid_infix_exception: public std::exception {
		const char* what() const noexcept {
			return "Invalid infix expression!";
		}
	};

public:

	/**
	 * Constructor
	 * @param[in]	factory		Factory to use to build the expression
	 */
	Postfix_Converter(Abstract_Expr_Factory& factory);

	/**
	 * Convert a tokenized infix expression to postfix. The pointers
	 * returned will be automatically freed by the factory whenever
	 * the factory is destructed.
	 *
	 * @param[in]	input		List of tokens
	 */
	Queue<Command*> convert_to_postfix(const std::string& input);


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
	 * Use the factory method pattern to return an operator command
	 *
	 * @param[in]	input		The string to convert to an operator
	 * @return		The associated operator
	 * @throws		invalid_operator_exception		Unknown operator
	 */
	Command* get_operator_command(const std::string& input);


	/**
	 * Add a left parenthesis to the current expression
	 *
	 * @param[in]	token		The string parenthesis token
	 * @throws 		invalid_infix_exception		Invalid expression
	 */
	void add_left_parenthesis(const std::string& token);

	/**
	 * Add a right parenthesis to the current expression
	 *
	 * @param[in]	token		The string parenthesis token
	 * @throws 		invalid_infix_exception		Invalid expression
	 */
	void add_right_parenthesis(const std::string& token);

	/**
	 * Compute logic associated with adding an operator to the expression
	 *
	 * @param[in]	token		Token operator to process
	 * @throws		invalid_infix_exception		Invalid expression
	 */
	void process_operator(const std::string& token);

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

	/// Temporary stack of string operators used while converting.
	Stack<std::string> stack;

	/// Final expression
	Queue<Command*> expression;

	/// True if previous statement was number, false otherwise
	bool last_token_number;
};


#endif	/* Postfix Converter Header Included */
