// ***************************************************
// ** Implements the functions from Stack class
// ***************************************************
#include "Stack.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
Stack<T>::Stack()
{
	// Set the strack basic attributes
	this->iSize = 0;
	this->currIndex = 0;

	// Allocate the memory for the linked list
	this->data = new LinkedList<T>;
}

/**
 * Returns the size of the stack
 * 
 * time complexity: O(1)
 */
template <typename T>
int Stack<T>::size() const
{
	return this->currIndex;
}

/**
 * Function to check whether or not the stack is empty
 * 
 * time complexity: O(1)
 */
template <typename T>
bool Stack<T>::isEmpty() const
{
	return (this->currIndex == 0 ? true : false);
}

/**
 * Method to add elements into the stack
 * 
 * time complexity: O(1)
 */
template <typename T>
void Stack<T>::push(T data_)
{
	// Add the new value to the stack
	this->data->push_front(data_);

	// Update the index
	this->currIndex++;
}

/**
 * Method to remove elements from the stack following LIFO
 * 
 * time complexity: O(1)
 */
template <typename T>
void Stack<T>::pop()
{
	// Check if the stack is empty
	if (this->isEmpty())
		cout << "<< Stack is Empty! >>" << endl; // stack underflow
	else
	{
		// Remove the value from the stack
		this->data->pop_front();

		// Update the index
		this->currIndex--;
	}
}

/**
 * Function to retrieve the last element from the stack
 * 
 * time complexity: O(1)
 */
template <typename T>
T Stack<T>::top() const
{
	// Check if the stack is empty
	if (this->isEmpty())
	{
		cout << "<< Stack is Empty! >>" << endl;
		return T();
	}
	else
	{
		// Return the last element from the stack
		return this->data->Head()->Next()->Data();
	}
}

/**
 * Method to print the stack
 * 
 * time complexity = O(n)
 */
template <typename T>
void Stack<T>::print(bool showLength_, string stackName_) const
{
	this->data->print(showLength_, stackName_);
}

// ***************************************************
// ** Overload operators
// ***************************************************