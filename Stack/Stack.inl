// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment


//
// Current Stack Size
//
template <typename T>
inline size_t Stack<T>::size(void) const {
	return this->next_index_;
}



//
// Get the top element on the stack
//
template <typename T>
inline const T& Stack<T>::top(void) const {
	if (this->is_empty()) {
		throw Stack<T>::empty_exception();
	}

	return this->stack_data_[this->next_index_ - 1];
}



//
// Test if the stack is empty
//
template <typename T>
inline bool Stack<T>::is_empty(void) const {
	return (this->next_index_ == 0);
}
