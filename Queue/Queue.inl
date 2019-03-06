// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.


//
// Is the queue empty?
//
template <typename T>
inline bool Queue<T>::is_empty (void) const {
	return (this->size() == 0);
}
