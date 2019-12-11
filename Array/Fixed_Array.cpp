// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <stdexcept> /* For std::out_of_range exception */

#define SWAP(x, y)    \
  {                   \
    auto temp = (x);  \
    (x)       = (y);  \
    (y)       = temp; \
  }
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

//
// Default Constructor
//
template<typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(void): data_(new T[N]) {}

//
// Initializing Constructor
//
template<typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const T& fill): Fixed_Array() {
  this->fill(fill);
}

//
// Copy Constructor
//
template<typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, N>& other): Fixed_Array() {
  Array_Base<T>::copy(this->data_, other.data_, N);
}

//
// Copy Constructor (with any sized array)
//
template<typename T, size_t N>
template<size_t M>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, M>& other): Fixed_Array() {
  // Copy the buffer up to the max size
  for (size_t index = 0; (index < N) && (index < M); ++index) { this->data_[index] = other[index]; }
}

//
// Destructor
//
template<typename T, size_t N>
Fixed_Array<T, N>::~Fixed_Array(void) {
  delete[] this->data_;
}

//
// Copy Assignment Operator for different sized array
//
template<typename T, size_t N>
template<size_t M>
const Fixed_Array<T, N>& Fixed_Array<T, N>::operator=(const Fixed_Array<T, M>& other) {
  // Test for self assignment
  if (this == &other) { return *this; }

  Fixed_Array<T, N> temp(other);
  Fixed_Array::swap(*this, temp);
  return *this;
}

//
// Element Access Operator
//
template<typename T, size_t N>
T& Fixed_Array<T, N>::operator[](size_t index) {
  if (index >= N) { throw std::out_of_range("index"); }

  return this->data_[index];
}

template<typename T, size_t N>
const T& Fixed_Array<T, N>::operator[](size_t index) const {
  if (index >= N) { throw std::out_of_range("index"); }

  return this->data_[index];
}

//
// Test two arrays for equality
//
template<typename T, size_t N>
template<size_t M>
bool Fixed_Array<T, N>::operator==(const Fixed_Array<T, M>& other) const {

  // Test for self comparison
  if (this == &other) { return true; }

  // Compare the sizes
  if (N != M) { return false; }

  // Compare the individual array elements
  for (size_t i = 0; i < N; ++i) {
    if (this->data_[i] != other.data_[i]) { return false; }
  }

  return true;
}

//
// Swap the internals of two array objects
//
template<typename T, size_t N>
void Fixed_Array<T, N>::swap(Fixed_Array& one, Fixed_Array& two) {
  SWAP(one.data_, two.data_);
}

// Undefine preprocessor macros
#undef SWAP
#undef MIN
