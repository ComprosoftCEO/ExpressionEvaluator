// -*- C++ -*-
// $Id: Queue.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.



//
// Is the queue empty?
//
template <typename T>
inline bool Queue <T>::is_empty (void) const {
	return (this->size() == 0);
}
