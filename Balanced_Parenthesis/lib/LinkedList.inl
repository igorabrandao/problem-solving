// ***************************************************
// ** Implements the functions from LinkedList class
// ***************************************************
#include "LinkedList.h"

// ***************************************************
// ** Functions
// ***************************************************

/**
 * Class constructor
 */
template <typename T>
LinkedList<T>::LinkedList()
{
	// Initialize the list basic attributes
	this->head = new Node<T>();
	this->tail = new Node<T>();
	this->listSize = 0;
}

/**
 * Class destructor
 */
template <typename T>
LinkedList<T>::~LinkedList()
{
	// Create a pointer to the list head
	Node<T> *currNode = this->head;
	Node<T> *nextNode;

	// Loop over the list until it reachs the tail
	while (currNode != nullptr)
	{
		nextNode = currNode->Next();
		delete currNode;
		currNode = nextNode;
	}
}

/**
 * Copy constructor (deep copy)
 * 
 * time complexity: O(n)
 */
template <typename T>
LinkedList<T>::LinkedList(const LinkedList &obj_)
{
	// Temp pointer to loop over the original list
	Node<T> *temp = obj_.head;

	// Initialize the list basic attributes
	this->head = new Node<T>();
	this->tail = new Node<T>();

	// Iterate through the end of the list
	while (temp && temp->Next())
	{
		/**
		 * Set the copied node as next of last node
		 * (Current List)->(Node)
		 */
		this->push_back(temp->Next()->Data());

		// Go to the next node of the original list
		temp = temp->Next();
	}

	// Set-up the copy list tail
	this->tail = temp;
}

/**
 * Function to add a value to the front of the list
 * 
 * time complexity = O(1)
 */
template <typename T>
void LinkedList<T>::push_front(T data_)
{
	// Create a new node
	Node<T> *newNode = new Node<T>(data_);

	if (this->head == nullptr)
	{
		// Handle first node push
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		/**
		 * Set Next of Node to Head of the current list
		 * (Node)->(Current List)
		 */
		newNode->setNext(this->head->Next());

		// Set the Head pointer to the new node
		this->head->setNext(newNode);
	}

	// Update the list size
	this->listSize++;
}

/**
 * Function to add a value to the back of the list
 * 
 * time complexity = O(1)
 */
template <typename T>
void LinkedList<T>::push_back(T data_)
{
	// Create the new node
	Node<T> *newNode = new Node<T>(data_);

	// List is empty so new node is a head
	if (this->head->Next() == nullptr)
	{
		this->head->setNext(newNode);
		this->tail = newNode;
	}
	else
	{
		// Set newNode as the next of the last node (tail)
		this->tail->setNext(newNode);

		// Assign the last element to the list tail
		this->tail = this->tail->Next();
	}

	// Update the list size
	this->listSize++;
}

/**
 * Function to remove the first value of the list
 * 
 * time complexity = O(1)
 */
template <typename T>
void LinkedList<T>::pop_front()
{
	// Check if the list has any elements
	if (this->head->Next() == nullptr)
	{
		// Delete the list head & tail
		delete this->head;
		delete this->tail;

		cout << "<< pop_front(): List already empty! >>" << endl;
	}
	else
	{
		// Create a pointer to the list head
		Node<T> *node = this->head;

		// Assign the head to the second element
		this->head = this->head->Next();

		// Delete the first element
		delete node;

		// Update the list size
		this->listSize--;
	}
}

/**
 * Function to remove the last value of the list
 * 
 * time complexity = O(n)
 */
template <typename T>
void LinkedList<T>::pop_back()
{
	if (this->head->Next() == nullptr)
	{
		// Delete the list head & tail
		delete this->head;
		delete this->tail;

		cout << "<< pop_back(): List already empty! >>" << endl;
	}
	else
	{
		Node<T> *secondLast = this->head;

		// Find the second last node
		while (secondLast->Next()->Next() != nullptr)
		{
			secondLast = secondLast->Next();
		}

		// Delete last node and second last becomes the last
		delete secondLast->Next();

		// Change next of second last node
		secondLast->setNext(nullptr);

		// Assign the last element to the tail
		this->tail = secondLast;
	}

	// Update the list size
	this->listSize--;
}

/**
 * Function to print the linked list
 * 
 * time complexity = O(n)
 */
template <typename T>
void LinkedList<T>::print(bool showLength_, string listName_) const
{
	// Create a pointer to the list head
	Node<T> *tmp = this->head;

	if (listName_.compare("") != 0)
		if (showLength_)
			cout << listName_ << "(" << this->length() << "): [ ";
		else
			cout << listName_ << ": [ ";
	else if (showLength_)
		cout << this->length() << ": [ ";
	else
		cout << "[ ";

	// Loop over the list until it reachs the tail
	while (tmp != nullptr)
	{
		if (tmp == this->head && tmp == this->tail)
			std::cout << tmp->Data() << "(H)(T) -> ";
		else if (tmp == this->head)
			std::cout << "(H) -> ";
		else if (tmp == this->tail)
			std::cout << tmp->Data() << "(T) -> ";
		else
			std::cout << tmp->Data() << " -> ";

		tmp = tmp->Next();
	}

	std::cout << "NULL ]\n";
}

/**
 * Function to return the number of elements in the list
 * 
 * time complexity = O(n)
 * space complexity = O(1)
 */
template <typename T>
int LinkedList<T>::length() const
{
	int size = 0;

	// Create a pointer to first element of the list
	Node<T> *tmp = this->head->Next();

	// Loop over the list until it reachs the tail
	while (tmp != nullptr)
	{
		tmp = tmp->Next();
		size++;
	}

	return size;
}

/**
 * Function to return the number of elements in the list (recursively)
 * 
 * time complexity = O(n)
 * space complexity = O(n) due to the use of the stack for recursion
 */
template <typename T>
int LinkedList<T>::recursiveLength(Node<T> *currNode_) const
{
	/**
	 * Check if the current node exists and if it's not the head
	 * we won't count the head!
	 */
	if (currNode_ == nullptr)
		return 0;
	else if (currNode_ == this->head && currNode_->Next())
		currNode_ = currNode_->Next();

	// Perform the recursive call
	return 1 + this->recursiveLength(currNode_->Next());
}

/**
 * Function to return the ith element from the list
 * 
 * time complexity = O(index_) | worst case: O(n)
 */
template <typename T>
Node<T> *LinkedList<T>::getIthNode(int index_) const
{
	// First of all check the validity of the index
	if (index_ < 0 || index_ >= this->listSize)
	{
		cout << "<< Index out of range! >>" << endl;
		return nullptr;
	}
	else
	{
		// Start the search from the first node, not from the head pointer
		Node<T> *currNode = this->head->Next();

		/**
		 * Iterate through the end of the list
		 */
		for (auto i = 0; i < index_; i++)
		{
			// Goto the next node
			currNode = currNode->Next();
		}

		return currNode;
	}

	cout << "<< Element not found! >>" << endl;
	return nullptr;
}

/**
 * Function to return the ith element value from the list
 * 
 * time complexity = O(index_) | worst case: O(n)
 */
template <typename T>
T LinkedList<T>::getIthNodeValue(int index_) const
{
	Node<T> *node = this->getIthNode(index_);
	return node != nullptr ? node->Data() : T();
}

/**
 * Function to add a new node at the ith position
 * 
 * time complexity = O(index_) | worst case: O(n)
 */
template <typename T>
void LinkedList<T>::insertIthNode(T data_, int index_)
{
	// First of all check the validity of the index
	if (index_ < 0 || index_ > this->listSize)
	{
		cout << "<< Index out of range! >>" << endl;
	}
	else if (index_ == 0)
	{
		// Insert at the beginning of the list
		this->push_front(data_);
	}
	else if (index_ == this->listSize)
	{
		// Insert at the end of the list
		this->push_back(data_);
	}
	else
	{
		// Access the node in the previous position
		Node<T> *prevNode = this->getIthNode(index_ - 1);

		// Create the new node
		Node<T> *newNode = new Node<T>(data_);

		// Update the links between the nodes
		newNode->setNext(prevNode->Next());
		prevNode->setNext(newNode);

		// Update the list size
		this->listSize++;
	}
}

/**
 * Function to delete the ith node
 * 
 * time complexity = O(index_) | worst case: O(n)
 */
template <typename T>
void LinkedList<T>::deleteIthNode(int index_)
{
	// First of all check the validity of the index
	if (index_ < 0 || index_ >= this->listSize)
	{
		cout << "<< Index out of range! >>" << endl;
	}
	else if (index_ == 0)
	{
		// Delete at the beginning of the list
		this->pop_front();
	}
	else if (index_ == (this->listSize - 1))
	{
		// Delete at the end of the list
		this->pop_back();
	}
	else
	{
		// Access the node in the previous position
		Node<T> *prevNode = this->getIthNode(index_ - 1);

		// Access the node in the current position
		Node<T> *currNode = prevNode->Next();

		// Update the links
		if (currNode && currNode->Next())
			prevNode->setNext(currNode->Next());
		else
			prevNode->setNext(nullptr);

		// Delete the node
		delete currNode;

		// Update the list size
		this->listSize--;
	}
}

/**
 * Function to delete the ith node from the end of the list
 * 
 * time complexity: O(n)
 * space complexity: O(1)
 */
template <typename T>
void LinkedList<T>::deleteIthNodeFromEnd(int nBeforeEnd_)
{
	// Check for edge cases
	if (this->head->Next() == nullptr)
	{
		cout << "<< Empty list! >>" << endl;
	}
	else if (nBeforeEnd_ < 0 || nBeforeEnd_ >= this->listSize)
	{
		cout << "<< Index out of range! >>" << endl;
	}
	else
	{
		// To do so, we'll need 2 pointers
		Node<T> *behindNode = this->head;
		Node<T> *fowardNode = this->head;

		// Advance the foward node n positions
		while (nBeforeEnd_--)
			fowardNode = fowardNode->Next();

		// Special case: the list length == n
		if (fowardNode == nullptr)
		{
			// Delete the list head
			Node<T> *node = this->head->Next();
			delete this->head;
			this->head = node;
		}

		// Traverse the list until the foward pointer reachs the last node
		while (fowardNode->Next() != nullptr)
		{
			behindNode = behindNode->Next();
			fowardNode = fowardNode->Next();
		}

		cout << "node to delete: " << behindNode->Next()->Data() << endl;

		// Keep track of the node that needs to be deleted
		Node<T> *node = behindNode->Next();

		// Connect the previous node with the next node of the one which needs to be deleted.
		behindNode->Next()->setNext(node->Next());

		// Delete the node
		delete node;
	}
}

/**
 * Function to search a node by it's value first occurrence
 * 
 * time complexity = O(n)
 */
template <typename T>
int LinkedList<T>::searchValue(T data_) const
{
	int index = -1;
	Node<T> *currNode = this->head->Next();

	// Iterate through the end of the list
	while (currNode)
	{
		// Increase the index
		index++;

		// Check if it's the searched value
		if (currNode->Data() == data_)
			return index;

		// Goto the next node
		currNode = currNode->Next();
	}

	return -1;
}

/**
 * Function to search a node by it's value first occurrence (recursively)
 * 
 * time complexity = O(n)
 * space complexity = O(n) due to the use of the stack for recursion
 */
template <typename T>
int LinkedList<T>::recursiveSearchValue(Node<T> *currNode_, T data_) const
{
	// Check if the current node exists and if it's not the head
	if (currNode_ == nullptr)
		return -1; // empty list
	else if (currNode_ == this->head && currNode_->Next())
		currNode_ = currNode_->Next();

	if (currNode_->Data() == data_)
		return 0; // data found!
	else
		return 1 + this->recursiveSearchValue(currNode_->Next(), data_);
}

/**
 * Function to return the midpoint node
 * 
 * time complexity = O(n)
 */
template <typename T>
Node<T> *LinkedList<T>::midpoint() const
{
	// Check if the list is empty
	if (this->head == nullptr || this->head->Next() == nullptr)
	{
		return nullptr; // empty list
	}
	else
	{
		// Use the slow & fast pointers approach
		Node<T> *slow = this->head->Next();
		Node<T> *fast = this->head->Next()->Next();

		while (fast && fast->Next())
		{
			// Jump 1 node for slow and 2 nodes for fast pointer
			slow = slow->Next();
			fast = fast->Next()->Next();
		}

		if (fast != nullptr)
			return slow->Next(); // List with even size

		// List with odd size
		return slow;
	}
}

/**
 * Function to return the midpoint node data
 */
template <typename T>
T LinkedList<T>::midpointData() const
{
	Node<T> *node = this->midpoint();
	return node != nullptr ? node->Data() : T();
}

/**
 * Function to reverse the list
 * 
 * time complexity = O(n)
 * space complexity = O(1)
 */
template <typename T>
void LinkedList<T>::reverse()
{
	// Check if the list is empty
	if (this->head != nullptr)
	{
		// We need 3 pointers to solve this
		Node<T> *prevNode = nullptr;
		Node<T> *currNode = this->head;

		while (currNode != nullptr)
		{
			Node<T> *nextNode = currNode->Next();
			currNode->setNext(prevNode);
			prevNode = currNode;
			currNode = nextNode;
		}

		this->head = prevNode;
		//this->tail = currNode;
	}
}

/**
 * Function to merge 2 sorted linked lists
 * 
 * time complexity: O(m+n)
 * 
 * space comlexity: O(1)
 */
template <typename T>
void LinkedList<T>::merge(Node<T> *list1_, Node<T> *list2_)
{
	// Check if the lists are not empty
	if (list1_ == nullptr)
		this->head = list2_;
	else if (list2_ == nullptr)
		this->head = list1_;

	// Create the head of the merged list
	Node<T> *finalHead = nullptr;

	// Initialize the finalHead pointer
	if (list1_->Data() < list2_->Data())
	{
		finalHead = list1_;
		list1_ = list1_->Next();
	}
	else
	{
		finalHead = list2_;
		list2_ = list2_->Next();
	}

	// Pointer to create the new nodes of the merged list
	Node<T> *node = finalHead;

	// Traverse both lists
	while (list1_ && list2_)
	{
		if (list1_->Data() < list2_->Data())
		{
			node->setNext(list1_); // insert at tail
			list1_ = list1_->Next();
		}
		else
		{
			node->setNext(list2_);
			list2_ = list2_->Next();
		}

		// Update the merged list tail
		node = node->Next();
	}

	// Handle the case where one list is longer than the other
	if (list1_)
		node->setNext(list1_); // Add the remaining of list1
	else
		node->setNext(list2_); // Add the remaining of list2

	// Return the head of the merged list
	this->head = finalHead->Next();
}

// ***************************************************
// ** Overload operators
// ***************************************************