// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition
#include "Array_Base.h"


/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array: public Array_Base<T>
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Array (void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Array (size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Array (size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Array (const Array & arr);

  /// Destructor.
  ~Array (void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Array & operator = (const Array & rhs);

  /**
   * Retrieve the current size of the array.
   *
   * @return          The current size
   */
  size_t size (void) const;

  /**
   * Retrieve the maximum size of the array.
   *
   * @return          The maximum size
   */
  size_t max_size (void) const;

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
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the 
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
  void resize (size_t new_size);

  /**
   * Test the array for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
  bool operator == (const Array & rhs) const;

  /**
   * Test the array for inequality.
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  bool operator != (const Array & rhs) const;


  ///Shrink the array to reclaim unused space
  void shrink (void);


  /**
   * The slice() method returns a deep copy of a portion of an array into
   * a new array object selected from begin to end (end not included). The original
   * array will not be modified.
   *
   * @param[in]       begin           The starting index
   * @return          A new Array object
   * @exception       std::out_of_range    Invalid index
   */
  Array slice (size_t begin) const;
  
  /**
   * @overload
   *
   * @param[in]       begin           The starting index
   * @param[in]       end             The ending index
   * @return          A new Array object
   * @exception       std::out_of_range    Invalid index
   */
  Array slice (size_t begin, size_t end) const;

  /**
   * Insert all of the data from the other array onto the end of this
   * current array, resizing the array if necessary. The other array
   * is not modified.
   *
   * @param[in]		other			Array to append onto this array
   */
  void append(const Array& other);


 
private:

  /**
   * Swap the internals of two arrays, such that all of the members of 
   *  one are stored inside two, and all of the members of two are stored
   *  inside one. The swap is not atomic.
   *
   * @param[in,out]  one              First array to swap the contents of
   * @param[in,out]  two              Second array to swap the contents of
   */
  static void swap(Array<T>& one, Array<T>& two);


  /// Pointer to the actual data.
  T * data_;

  /// Current size of the array.
  size_t cur_size_;

  /// Maximum size of the array.
  size_t max_size_;
};


// include the inline files
#include "Array.inl"

// include the source file since template class
#include "Array.cpp"

#endif   /* Array Header Included */
