//==============================================================================
/**
 * @file       Stack.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef STACK_HEADER
#define STACK_HEADER

#include <Array.h>
#include <exception>

/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template<typename T>
class Stack {
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
   */
  class empty_exception: public std::exception {

  public:
    const char* what() const noexcept {
      return "Stack underflow!";
    }
  };

  /// Default constructor.
  Stack(void);

  /// Copy constructor.
  Stack(const Stack& s);

  /// Destructor.
  ~Stack(void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  Stack<T>& operator=(const Stack<T>& rhs);

  /**
   * Push a new \a element onto the stack. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void push(const T& element);

  /**
   * Remove the top-most element from the stack.
   *
   * @exception      empty_exception    The stack is empty.
   * @return			Object popped off the stack
   */
  T pop(void);

  /**
   * Get the top-most element on the stack. If there are no element
   * on the stack, then the stack_is_empty exception is thrown.
   *
   * @return         Element on top of the stack.
   * @exception      empty_exception    The stack is empty
   */
  const T& top(void) const;

  /**
   * Test if the stack is empty
   *
   * @retval         true          The stack is empty
   * @retval         false         The stack is not empty
   */
  bool is_empty(void) const;

  /**
   * Number of element on the stack.
   *
   * @return         Size of the stack.
   */
  size_t size(void) const;

  /// Remove all elements from the stack.
  void clear(void);

private:
  /// Where the actual stack entries are stored
  Array<T> stack_data_;

  /// Index for where to put the next item on the stack
  size_t next_index_;
};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif /* Stack Header Included */
