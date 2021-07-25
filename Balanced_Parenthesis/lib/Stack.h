/*!
	<PRE>
	SOURCE FILE : Stack.h
	DESCRIPTION.: Stack class based on custom Linked List - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 25th, 2021.
	</pre>
*/
#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include <string>
#include "../../../Linked_List/include/LinkedList.h"

using namespace std;

/**
 * Stack template class
 */
template <class T>
class Stack
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    LinkedList<T> *data; // Points to the Linked List head
    int iSize;           // Stack max size
    int currIndex;       // Holds the current position on the stack

    inline Stack(const Stack &){/* empty */}; // Disable copy constructor

public:
    // ***************************************************
    // ** Functions
    // ***************************************************
    Stack();                                        // Class constructor
    inline ~Stack(){/* empty */};                   // Class Destructor
    int size() const;                               // Returns the size of the stack
    bool isEmpty() const;                           // Function to check whether or not the stack is empty
    void push(T data_);                             // Method to add elements into the stack
    void pop();                                     // Method to remove elements from the stack following LIFO
    T top() const;                                  // Function to retrieve the last element from the stack
    void print(bool, string stackName_ = "") const; // Method to print the stack

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "Stack.inl"
#endif

/* --------------------- [ End of the Stack.h header ] ------------------- */
/* ============================================================================ */