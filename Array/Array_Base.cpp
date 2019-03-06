// $Id: Array_Base.cpp 380 2019-02-19 11:46:33Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception



//
// Destructor
//
template <typename T>
Array_Base <T>::~Array_Base (void) {}




//
// Find a value in the array
//
template  <typename T>
int Array_Base <T>::find (T element) const {
	try {
		return this->find(element,0);
	} catch (...) {
		return DATA_NOT_FOUND;
	}
}

template <typename T>
int Array_Base <T>::find (T element, size_t start) const {
	if (start >= this->size()) {
		throw std::out_of_range("start");
	}

	for (size_t i = start; i < this->size(); ++i) {
		if ((*this)[i] == element) {return i;}
	}

	return DATA_NOT_FOUND;
}



//
// Fill the array with a single element
//
template <typename T>
void Array_Base <T>::fill (T element) {
	for (size_t i = 0; i < this->size(); ++i) {
		(*this)[i] = element;
	}
}


//
// Reverse the order of the elements in the array
//
template <typename T>
void Array_Base <T>::reverse (void) {

	size_t forward_index = 0;					// Counts forward
	size_t backward_index = this->size() - 1;	// Counts backward
	size_t middle = (this->size() / 2);

	for (; forward_index < middle; ++forward_index, --backward_index) {

		//Standard swap code
		T temp = (*this)[forward_index];
		(*this)[forward_index] = (*this)[backward_index];
		(*this)[backward_index] = temp;
	}
}


//
// Copy data from one buffer to another
//
template <typename T>
void Array_Base <T>::copy(T* dest, const T* src, size_t len) {
	for (size_t i = 0; i < len; ++i) {
		dest[i] = src[i];
	}
}
