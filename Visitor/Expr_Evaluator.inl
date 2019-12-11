// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment

//
// Reset the evaluator state
//
inline void Expr_Evaluator::reset_evaluator() {
  this->stack_.clear();
}

//
// Get the result of the last expression
//
inline int Expr_Evaluator::get_result() const {
  return this->stack_.top();
}
