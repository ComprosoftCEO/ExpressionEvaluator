//==============================================================================
/**
 * @file       Array_Base.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef ARRAY_BASE_HEADER
#define ARRAY_BASE_HEADER


#include <cstring>          // for size_t definition


//For find method
#define DATA_NOT_FOUND -1


template <typename T>
class Array_Base
{
public:
	/// Type definition of the element type.
	typedef T type;

	/// Destructor
	virtual ~Array_Base(void);

	/**
	 * Retrieve the current size of the array.
	 *
	 * @return          The current size
	 */
	virtual size_t size(void) const = 0;

	/**
	 * Get the value at the specified index. If the index is not
	 * within the range of the array, then std::out_of_range exception
	 * is thrown.
	 *
	 * @param[in]       index               Zero-based location
	 * @exception       std::out_of_range   Invalid \a index value
	 */
	virtual T& operator[](size_t index) = 0;

	/**
	 * @overload
	 *
	 * The returned value is not modifiable.
	 */
	virtual const T& operator[](size_t index) const = 0;

	/**
	 * Get the value at the specified index. If the \a index is not within
	 * the range of the array, then std::out_of_range exception is thrown.
	 *
	 * @param[in]       index                 Zero-based location
	 * @return          Character at \index
	 * @exception       std::out_of_range     Invalid index value
	 */  
	T get(size_t index) const;

	/** 
	 * Set the value at the specified \a index. If the \a index is not
	 * within range of the array, then std::out_of_range exception is 
	 * thrown.
	 *
	 * @param[in]       index                 Zero-based location
	 * @param[in]       value                 New value for character
	 * @exception       std::out_of_range     Invalid \a index value
	 */
	void set(size_t index, T value);

	/**
	 * Locate the specified character in the array. The index of the first
	 * occurrence of the character is returned. If the character is not
	 * found in the array, then DATA_NOT_FOUND is returned.
	 *
	 * @param[in]        element              Value to search for
	 * @return           Index value of the element
	 * @retval           DATA_NOT_FOUND       Value not found
	 */
	int find(T element) const;

	/**
	 * @overload
	 *
	 * This version allows you to specify the start index of the search. If
	 * the start index is not within the range of the array, then the
	 * std::out_of_range exception is thrown.
	 *
	 * @param[in]       element              Value to search for
	 * @param[in]       start                Index to begin search
	 * @return          Index value of first occurrence
	 * @retval          DATA_NOT_FOUND       Character not found
	 * @exception       std::out_of_range    Invalid index
	 */
	int find(T element, size_t start) const;

	/**
	 * Fill the contents of the array.
	 *
	 * @param[in]       element              Fill value
	 */
	void fill(T element);

	/// Reverse the contents of the array such that the first element is now
	/// the last element and the last element is the first element.
	void reverse(void);


protected:
	/**
	 * Copy data from one buffer to another, given the number of elements
	 *  to copy. Assumes that the source and destination DO NOT overlap, or 
	 *  the behavior is undefined.
	 *
	 * @param[out]      dest            Destination for the data being copied
	 * @param[in]       src             Source for the data being copied
	 * @param[in]       len             Number of bytes to copy
	 */
	static void copy(T* dest, const T* src, size_t len);

};


// Include the inline files
#include "Array_Base.inl"

// Include the source file since template class
#include "Array_Base.cpp"


#endif   /* Array Base Header Included */
