// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment

//
// Get the variable name
//
inline const std::string& Variable_Command::get_name() const {
  return this->name_;
}

//
// Get the variable value
//
inline int Variable_Command::get_value() const {
  return this->value_;
}

//
// Set the variable value
//
inline void Variable_Command::set_value(int new_value) {
  this->value_ = new_value;
}
