// $Id: Queue.cpp 827 2011-02-07 14:20:53Z hillj $

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
Queue <T>::Queue(void):
  queue_data_(DEFAULT_SIZE),
  insert_index_(0),
  remove_index_(0),
  is_full_(false) {}




//
// Copy Constructor
//
template <typename T>
Queue <T>::Queue(const Queue<T>& other):
  queue_data_(other.queue_data_),
  insert_index_(other.insert_index_),
  remove_index_(other.remove_index_),
  is_full_(other.is_full_) {}




//
// Destructor
//
template <typename T>
Queue <T>::~Queue() {}



//
// Assignment Operator
//
template <typename T>
const Queue<T> & Queue<T>::operator = (const Queue & other) {
	
	//Test for self assignment
	if (this == &other) {return *this;}

	this->queue_data_ = other.queue_data_;
	this->insert_index_ = other.insert_index_;
	this->remove_index_ = other.remove_index_;
	this->is_full_ = other.is_full_;

	return *this;
}




//
// Add an element into the queue
//
template <typename T>
void Queue <T>::enqueue(T element) {

	//Test for a full circular queue
	if (this->is_full_) {
		this->increase_queue_size();
	}

	this->queue_data_[this->insert_index_] = element;
	this->circular_increment_index(this->insert_index_);

	//Test for a full queue
	if (this->insert_index_ == this->remove_index_) {
		this->is_full_ = true;
	} else {
		this->is_full_ = false;
	}
}




//
// Remove the front element from the queue
//
template <typename T>
T Queue <T>::dequeue(void) {

	if (this->is_empty()) {
		throw Queue<T>::empty_exception();
	}

	T ret_val = this->queue_data_[this->remove_index_];
	this->circular_increment_index(this->remove_index_);
	this->is_full_ = false;

	return ret_val;
} 




//
// Number of elements in the queue
//
template <typename T>
size_t Queue <T>::size (void) const {
	if (this->is_full_) {
		return this->queue_data_.size();
	}

	//Find difference between remove and insert indexes
	//  This might require us to wrap around, if remove is after insert
	if (this->insert_index_ >= this->remove_index_) {
		return (this->insert_index_ - this->remove_index_);
	} else {
		return (this->insert_index_ - this->remove_index_) + this->queue_data_.size();
	}
}







//
// Clear any elements from the queue
//
template <typename T>
void Queue <T>::clear(void) {
	insert_index_ = 0;
	remove_index_ = 0;
	is_full_ = false;
}




//
// Circular Increment Method
//
template <typename T>
void Queue <T>::circular_increment_index(size_t& index) {
	index = (index + 1) % this->queue_data_.size();
}





//
// Add more space to a full queue
//
template <typename T>
void Queue <T>::increase_queue_size (void) {

	this->split_and_mend();

	//Compute the new queue size
	size_t old_size = this->queue_data_.size();
	size_t new_size = this->queue_data_.size() + DEFAULT_INCREASE;
	this->queue_data_.resize(new_size);
		
	//Fix the insert index to point to the empty space
	this->insert_index_ = old_size;
	this->is_full_ = false;
}



//
// Split and mend the circular queue
//
template <typename T>
void Queue <T>::split_and_mend (void) {
	// NONE GREADED COMMENT: This is a good use of the slice method to
	// help with unwinding the queue when resizing the underlying array.
	//
	// RESPONSE: Thank you for the compliment :)
	Array<T> front(this->queue_data_);
	Array<T> back; 

	front.resize(this->insert_index_);
	back = this->queue_data_.slice(this->insert_index_);	
	back.append(front);

	this->queue_data_ = back;
	this->insert_index_ = this->remove_index_ = 0;
}



//Undefine preprocessor macros
#undef DEFAULT_SIZE
#undef DEFAULT_INCREASE
