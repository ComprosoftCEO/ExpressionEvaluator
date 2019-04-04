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
 * @class invalid_state_exception
 *
 * Thrown when trying to perform an action on a builder when you
 * aren't allowed to do so. For example, adding a token before
 * calling start_new_expression().
 */
class invalid_state_exception: public std::exception {
	const char* what() const noexcept {
		return "Invalid builder state!";
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



/**
 * @class no_expression_exception
 *
 * Trying to get the last expression before an expression has been created
 */
class no_expression_exception: public std::exception {
	const char* what() const noexcept {
		return "No expression has been created yet!";
	}
};
