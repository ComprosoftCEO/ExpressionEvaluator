// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS507_FIXED_ARRAY_H_
#define _CS507_FIXED_ARRAY_H_


#include "Array_Base.h"


/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array so it can inherit of 
 * the Array class's methods.
 */
template <typename T, size_t N>
class Fixed_Array : public Array_Base<T>
{
public:
  /// Default constructor.
  Fixed_Array (void);

  /**
   * Initializing constructor. Fills the contents of the 
   * array with the specified \a fill value.
   *
   * @param[in]      fill       The file value.
   */
  Fixed_Array (T fill);

  /**
   * Copy constructor.
   *
   * @param[in]      arr        Source array
   */
  Fixed_Array (const Fixed_Array <T, N> & arr);
	
  /**
   * Initializing constructor. The source array can be of any size
   * as long as they are of the same type.
   *
   * @param[in]      arr        Source array
   */
  template <size_t M>
  Fixed_Array (const Fixed_Array <T, M> & arr);

  /// Destructor.
  ~Fixed_Array (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  const Fixed_Array & operator = (const Fixed_Array <T, N> & rhs);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  template <size_t M>
  const Fixed_Array & operator = (const Fixed_Array <T, M> & rhs);

  /**
   * Retrieve the current size of the array.
   *
   * @return          The current size
   */
  size_t size (void) const;

  /**
   * Get the value at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   * @exception       std::out_of_range   Invalid \a index value
   */
  T & operator [] (size_t index);

  /**
   * @overload
   *
   * The returned value is not modifiable.
   */
  const T & operator [] (size_t index) const;

  /**
   * Test the array for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
  bool operator == (const Fixed_Array <T, N> & rhs) const;


  /**
   * @override The two arrays can be different lengths
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
  template <size_t M>
  bool operator == (const Fixed_Array <T, M> & rhs) const;

  /**
   * Test the array for inequality.
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  bool operator != (const Fixed_Array <T, N> & rhs) const;

  /**
   * @override The two arrays can be different lengths
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  template <size_t M>
  bool operator != (const Fixed_Array <T, M> & rhs) const;



private:
  /**
   * Swap the internals of two arrays, such that all of the members of 
   *  one are stored inside two, and all of the members of two are stored
   *  inside one. The swap is not atomic.
   *
   * @param[in,out]  one              First array to swap the contents of
   * @param[in,out]  two              Second array to swap the contents of
   */
  static void swap(Fixed_Array& one, Fixed_Array& two);

  /// Pointer to the actual data.
  T * data_;
};

// include the inline files
#include "Fixed_Array.inl"

// include the source file since template class
#include "Fixed_Array.cpp"

#endif  // !defined _CS507_FIXED_ARRAY_H_
