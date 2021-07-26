/*!
	<PRE>
	SOURCE FILE : LinkedList.h
	DESCRIPTION.: LinkedList class - with implementation.
	AUTHOR......: Igor A. Brandão
	LOCATION....: NATAL/RN.
	SATARTED ON.: July/2021

	TO COMPILE..: Use makefile.
	OBS.........: Part of Data Structures Project.

	tail UPDATE.: July 23th, 2021.
	</pre>
*/
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include <string>

using namespace std;

/**
 * Node template class
 */
template <class T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    // ***************************************************
    // ** Methods
    // ***************************************************
    // Class constructor
    Node() : next(nullptr){};

    // Class constructor overload
    Node(T data_) : data(data_), next(nullptr){};

    // Adds the given node as next of the current node
    inline void setNext(Node *node) { this->next = node; };

    // Return pointer of the next node
    inline Node *Next() { return this->next; };

    // Returns data of the current node
    inline T Data() { return this->data; };
};

/**
 * LinkedList template class
 */
template <class T>
class LinkedList
{
private:
    // ***************************************************
    // ** Attributes
    // ***************************************************
    Node<T> *head;    // The head of the list
    Node<T> *tail;    // The tail of the list

public:
    int listSize = 0; // The list size
    
    // ***************************************************
    // ** Functions
    // ***************************************************
    LinkedList();                                       // Class constructor
    ~LinkedList();                                      // Class Destructor
    LinkedList(const LinkedList &obj_);                 // Copy constructor
    void push_front(T data_);                           // Function to add a value to the front of the list
    void push_back(T data_);                            // Function to add a value to the back of the list
    void pop_front();                                   // Function to remove the first value of the list
    void pop_back();                                    // Function to remove the last value of the list
    void print(bool, string llName_ = "") const;        // Function to print the linked list
    int length() const;                                 // Function to return the number of elements in the list
    int recursiveLength(Node<T> *) const;               // Function to return the number of elements in the list (recursively)
    Node<T> *getIthNode(int index_) const;              // Function to return the ith element from the list
    T getIthNodeValue(int index_) const;                // Function to return the ith element value from the list
    void insertIthNode(T data_, int index_);            // Function to add a new node at the ith position
    void deleteIthNode(int index_);                     // Function to delete the ith node
    void deleteIthNodeFromEnd(int nBeforeEnd_);         // Function to delete the ith node from the end of the list
    int searchValue(T data_) const;                     // Function to search a node by it's value first occurrence
    int recursiveSearchValue(Node<T> *, T data_) const; // Function to search a node by it's value first occurrence (recursively)
    Node<T> *midpoint() const;                          // Function to return the midpoint node
    T midpointData() const;                             // Function to return the midpoint node data
    void reverse();                                     // Function to reverse the list
    void merge(Node<T> *, Node<T> *);                   // Function to merge 2 sorted linked lists

    // Return pointer to the list head
    inline Node<T> *Head() { return this->head; };
    inline void setHead(Node<T> *head_) { this->head = head_; };

    // Return pointer to the list tail
    inline Node<T> *Tail() { return this->tail; };

    // ***************************************************
    // ** Overload operators
    // ***************************************************
};

#include "LinkedList.inl"
#endif

/* --------------------- [ End of the LinkedList.h header ] ------------------- */
/* ============================================================================ */