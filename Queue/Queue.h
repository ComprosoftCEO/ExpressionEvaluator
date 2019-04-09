//==============================================================================
/**
 * @file       Queue.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef QUEUE_HEADER
#define QUEUE_HEADER


#include <exception>
#include <Array.h>


/**
 * @class Queue
 *
 * Basic queue for arbitrary elements
 */
template <typename T>
class Queue {

public:
	/// Type definition of the type
	typedef T type;

	/**
	 * @class empty_exception
	 *
	 * Exception thrown to indicate the queue is empty.
	 */
	class empty_exception : public std::exception {

	public:
		const char* what() const noexcept {
			return "Queue underflow!";
		}
	};

	/// Default Constructor
	Queue(void);

	/// Copy Constructor
	Queue(const Queue<T>& other);

	/// Destructor
	~Queue(void);

	/**
	 * Assignment operator
	 *
	 * @param[in]      rhs           Right-hand side of operator
	 * @return         Reference to self
	 */
	const Queue<T>& operator=(const Queue<T>& rhs);

	/**
	 * Add a new \a element into the queue. The element is inserted
	 * behind all the other elements in the list.
	 *
	 * @param[in]      element       Element to add to the queue
	 */
	void enqueue(const T& element);

	/**
	 * Remove the front element from the queue.
	 *
	 * @return         The removed element
	 * @exception      empty_exception    The queue is empty.
	 */
	T dequeue(void);

	/**
	 * Test if the queue is empty
	 *
	 * @retval         true          The queue is empty
	 * @retval         false         The queue is not empty
	 */
	bool is_empty(void) const;

	/**
	 * Number of element in the queue
	 *
	 * @return         Size of the queue
	 */
	size_t size(void) const;

	/// Clear any elements in the queue
	void clear(void);

private:

	/**
	 * Do a circular increment to the index, based on the size of queue data.
	 * So, if queue data is size 10, and the index is 9, (9+1) mod 10 = 0.
	 *
	 * @param[out]		index		Reference to the index to increment
	 */
	void circular_increment_index(size_t& index);


	/// Add more space to the queue.
	/// Only call this method with a full queue.
	void increase_queue_size(void);


	/** Re-arrange the queue data values so that the first element in queue data
	 *   is the first element to dequeue, instead of having a circular reference
	 *   that prevents the array from being resized.
	 * 
	 *  For example, if I have the queue:
	 *       [4][5][6][1][2][3]
	 *  It becomes
	 *       [1][2][3][4][5][6]
	 *
	 * This method is designed to only work with a full queue
	 */
	void split_and_mend(void);



	/// Where the actual queue entries are stored
	Array<T> queue_data_;

	/// Where to insert the next item 
	size_t insert_index_;

	/// Where to remove the next item from
	size_t remove_index_;

	/// Flag set to indicate that the circular queue is full
	bool is_full_;

};


// Include the inline files
#include "Queue.inl"

// Include the source file since template class
#include "Queue.cpp"


#endif	/* Queue Header Included */
