// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment

//
// Reset the internal state
//
inline void Variable_Getter::reset() {
  this->variables_.clear();
}

//
// Get the stored map of variables
//
inline const std::map<std::string, int>& Variable_Getter::get_variables() const {
  return this->variables_;
}
