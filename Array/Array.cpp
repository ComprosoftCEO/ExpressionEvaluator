// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


#include <stdexcept>	/* For std::out_of_bounds exception */

#define DEFAULT_SIZE 10
#define SWAP(x,y) {auto temp = (x); (x) = (y); (y) = temp;}



//
// Default constructor
//
template <typename T>
Array<T>::Array(void):
  Array(DEFAULT_SIZE)
{
	this->cur_size_ = 0;
}


//
// Initializing constructor
//
template <typename T>
Array<T>::Array(size_t length):
  data_(new T[length]),
  cur_size_(length),
  max_size_(length) {}



//
// Initializing constructor
//
template <typename T>
Array<T>::Array(size_t length, T fill):
  Array(length)
{
	this->fill(fill);
}



//
// Copy Constructor
//
template <typename T>
Array<T>::Array(const Array & other):
  data_(new T[other.cur_size_]),
  cur_size_(other.cur_size_),
  max_size_(other.cur_size_)
{
	Array_Base<T>::copy(this->data_,other.data_,other.cur_size_);
}



//
// Destructor
//
template <typename T>
Array<T>::~Array(void) {
	delete[] this->data_;
}



//
// Copy Assignment Operator
//
template <typename T>
const Array<T>& Array<T>::operator=(const Array& other) {
	//Test for self assignment
	if (this == &other) {return *this;}

	Array temp(other);
	Array::swap(*this, temp);
	return *this;
}



//
// Element Access Operator
//
template <typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= this->cur_size_) {
		throw std::out_of_range("index");
	}

	return this->data_[index];
}


template <typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= this->cur_size_) {
		throw std::out_of_range("index");
	}

	return this->data_[index];
}



//
// Resize the array
//
template <typename T>
void Array<T>::resize(size_t new_size) {
	if (new_size > this->max_size_) {

		//Create a new buffer
		Array temp(new_size);
		Array_Base<T>::copy(temp.data_,this->data_,this->cur_size_);
		Array::swap(*this,temp);

	} else {

		//Merely truncate the array
		this->cur_size_ = new_size;
	}
}



//
// Test two arrays for equality
//
template <typename T>
bool Array<T>::operator==(const Array& other) const {

	//Test for self comparison
	if (this == &other) {return true;}

	//Array sizes must match
	if (this->cur_size_ != other.cur_size_) {return false;}

	//Compare the individual array elements
	for (size_t i = 0; i < this->cur_size_; ++i) {
		if (this->data_[i] != other.data_[i]) {return false;}
	}

	return true;
}





//
// Shrink the array to reclaim space
//
template <typename T>
void Array<T>::shrink() {
	if (this->cur_size_ < this->max_size_) {
		Array temp(this->cur_size_);
		Array_Base<T>::copy(temp.data_,this->data_,this->cur_size_);
		Array::swap(*this,temp);
	}
}





//
// Slice the array
//
template <typename T>
Array<T> Array<T>::slice(size_t begin, size_t end) const {  

	if (begin >= this->cur_size_) {
		throw std::out_of_range("begin");
	}

	if ((end > this->cur_size_) || (end <= begin)) {
		throw std::out_of_range("end");
	}


	size_t split_length = end - begin;
	Array temp(split_length);
	Array_Base<T>::copy(temp.data_,this->data_ + begin, split_length);

	return temp;
}



//
// Append data onto this Array
//
template <typename T>
void Array <T>::append(const Array& other) {

	size_t old_size = this->cur_size_;
	size_t new_size = this->cur_size_ + other.cur_size_;

	Array temp(new_size);

	//Copy the new data from the Array
	Array_Base<T>::copy(temp.data_, this->data_, this->cur_size_);
	Array_Base<T>::copy(temp.data_ + old_size, other.data_, other.cur_size_);
	Array::swap(*this,temp);
}



//
// Swap the internals of two array objects
//
template <typename T>
void Array <T>::swap(Array<T>& one, Array<T>& two) {
	SWAP(one.data_, two.data_);
	SWAP(one.cur_size_, two.cur_size_);
	SWAP(one.max_size_, two.max_size_);
}




//Undefine preprocessor macros
#undef DEFAULT_SIZE
#undef SWAP
