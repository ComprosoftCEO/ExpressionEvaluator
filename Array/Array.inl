// -*- C++ -*-
// $Id: Array.inl 828 2011-02-07 14:21:52Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


//
// Current Array Size
//
template <typename T>
inline size_t Array <T>::size (void) const {
	return this->cur_size_;
}

//
// Maximum Array Size
//
template <typename T>
inline size_t Array <T>::max_size (void) const {
	return this->max_size_;
}




//
// Test two arrays for inequality
//
template <typename T>
inline bool Array <T>::operator != (const Array & other) const {
	return !(*this == other);
}



//
// Slice the array
//
template <typename T>
inline Array<T> Array <T>::slice (size_t begin) const {
	return this->slice(begin,this->cur_size_);
}
