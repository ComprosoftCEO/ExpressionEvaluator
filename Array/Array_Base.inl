// -*- C++ -*-
// $Id: Array_Base.inl 828 2011-02-07 14:21:52Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


//
// Get value at a specified index
//
template <typename T>
inline T Array_Base <T>::get (size_t index) const {
	return (*this)[index];
}


//
// Set a value at a specified index
//
template <typename T>
inline void Array_Base <T>::set (size_t index, const T& value) {
	(*this)[index] = value;
}
