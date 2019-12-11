// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Current Array Size
//
template<typename T, size_t N>
inline size_t Fixed_Array<T, N>::size(void) const {
  return N;
}

//
// Copy Assignment Operator
//
template<typename T, size_t N>
inline const Fixed_Array<T, N>& Fixed_Array<T, N>::operator=(const Fixed_Array<T, N>& other) {
  return Fixed_Array<T, N>::operator=<N>(other);
}

//
// Test the two arrays for equality
//
template<typename T, size_t N>
inline bool Fixed_Array<T, N>::operator==(const Fixed_Array<T, N>& other) const {
  return this->operator==<N>(other);
}

//
// Test two arrays for inequality
//
template<typename T, size_t N>
inline bool Fixed_Array<T, N>::operator!=(const Fixed_Array<T, N>& other) const {
  return this->operator!=<N>(other);
}

template<typename T, size_t N>
template<size_t M>
inline bool Fixed_Array<T, N>::operator!=(const Fixed_Array<T, M>& other) const {
  return !(*this == other);
}
