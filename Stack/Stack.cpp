// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment


#define DEFAULT_SIZE     32
#define DEFAULT_INCREASE 32


//
// Default Constructor
//
template <typename T>
Stack<T>::Stack(void):
  stack_data_(DEFAULT_SIZE),
  next_index_(0) {}



//
// Copy Constructor
//
template <typename T>
Stack<T>::Stack(const Stack& other):
  stack_data_(other.stack_data_),
  next_index_(other.next_index_) {}



//
// ~Stack
//
template <typename T>
Stack<T>::~Stack(void) {}


//
// Copy Assignment Operator
//
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {

	//Test for self-assignment
	if (this == &other) {return *this;}

	this->stack_data_ = other.stack_data_;
	this->next_index_ = other.next_index_;

	return *this;
}



//
// Add a value to the stack
//
template <typename T>
void Stack<T>::push(const T& element) {

	//When to allocate more space for the stack	
	if (this->next_index_ >= this->stack_data_.size()) {
		size_t new_size = this->stack_data_.size() + DEFAULT_INCREASE;
		this->stack_data_.resize(new_size);
	}

	//Add the element into the stack
	this->stack_data_[next_index_] = element;
	this->next_index_ += 1;
}



//
// Remove the top value from the stack
//
template <typename T>
T Stack<T>::pop(void) {
	if (this->is_empty()) {
		throw Stack<T>::empty_exception();
	}

	this->next_index_ -= 1;
	return this->stack_data_[next_index_];
}


//
// Clear all elements in the stack
//
template <typename T>
void Stack<T>::clear(void) {
	this->next_index_ = 0;
}




//Undefine preprocessor macros
#undef DEFAULT_SIZE
#undef DEFAULT_INCREASE
