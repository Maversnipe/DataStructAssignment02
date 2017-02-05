#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Lucas Nguyen Thai Vinh
 *  \date      4 Feb 2017
 *  \note      162548Y
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() : head_(NULL)
{
}

LinkedList::~LinkedList()
{ 
	if (size() != 0)
	{ // If there is still undeleted Nodes
		Node* toDelete = head_;		// Initialise toDelete as head_ to start from beginning
		while (toDelete != NULL)
		{ // Deletes nodes as it traverses to the end of linked list
			Node* nextToDelete = toDelete->next;
			delete toDelete;
			toDelete = nextToDelete;
		}
	}
}

void LinkedList::push_front(int data)
{
	Node* newNode = new Node(data);			// Create a new node with the new data inside
	if (head_ == NULL)
	{ // If head_ is NULL
		head_ = newNode;					// Point head pointer to newNode
	}
	else
	{ // If head_ is not NULL
		newNode->next = head_;				// Point newNode's next pointer to the original head_
		head_ = newNode;					// Point head_ to the newNode
	}
}

void LinkedList::push_back(int data)
{
	Node* newNode = new Node(data);			// Create a new node with the new data inside
	if (head_ == NULL)
	{
		head_ = newNode;
	}
	else
	{ // If head_ is not NULL
		Node* curr = head_;					// Create a new node pointer, curr, which points to where head_ is pointing

		while (curr->next != NULL) // Loops to end of linked list
			curr = curr->next;

		curr->next = newNode;				// Points the last node's next pointer to the new node
	}
}

int LinkedList::pop_front()
{
	int deletedVal = 0;			// Create an int to store the value of the deleted node

	if (head_ == NULL)	
		return deletedVal;		// Returns 0 if head_ is NULL

	Node* curr = head_;			// Create a node pointer, curr, which points to where head_ is pointing
	head_ = head_->next;		// Points head pointer to the next node
	deletedVal = curr->data;	// Put the value of the node to be popped into deletedVal
	delete curr;				// Delete the curr Pointer

    return deletedVal;			// Returns the popped node's value
}

int LinkedList::pop_back()
{    
	int deletedVal = 0;			// Initialise the int for the deleted value
	
	if (head_ == NULL)
		return deletedVal;		// Returns 0 if head_ is NULL
	else if (head_->next == NULL)
		return pop_front();		// Pops  front if head_->next is NULL, since there is only one Node left

	Node* curr = head_->next;	// Initialise pointer, curr, to head_->next
	Node* beforeCurr = head_;	// Initialise pointer, beforeCurr, to head_ 
	while (curr->next != NULL)
	{ // Keeps looping until curr is pointing to the last node 
		// (Traversal of Linked List)
		beforeCurr = curr;		
		curr = curr->next;		
	}
	deletedVal = curr->data;	// Put the value of the deleted Node into deletedVal

	delete curr;				// Delete the Node
	beforeCurr->next = NULL;	// Point the next pointer for the node before the deleted node to NULL

    return deletedVal;			// Returns the deleted node's value
}

void LinkedList::insert_at(int pos, int data)
{ 
	if (pos <= 0) 
	{ // If the position is <= 0, push_front() is called as it will be inserting at the front of the linked list
		push_front(data);
	}
	else if ((size_t)pos >= (size()))
	{ // If the position is >= size(), push_back() is called as it is inserting at the back of the linked list
		push_back(data);
	}
	else if ((size_t)pos < size())
	{ // This shows that position is between start and end of linked list
		Node* beforeCurr = head_;
		Node* curr = head_->next;
		Node* newNode = new Node(data);

		for (int placeToBeInserted = 1; placeToBeInserted < pos; placeToBeInserted++)
		{ // Traversal of linked list until position
			beforeCurr = curr;
			curr = curr->next;
		}

		beforeCurr->next = newNode;		// Points the pointer before the node at the position originally to new node
		newNode->next = curr;			// Points the newNode to the node that was originally at the position
	}
}

int LinkedList::pop_at(int pos)
{
	if (head_ == NULL) // If there is no nodes (head_ == NULL), return 0
		return 0;

	if (pos <= 0)
	{ // If the position is <= 0, pop_front is called as the first node of the linked list is popped
		return pop_front();
	}
	else
	{ // If position is > 0
		int deletedVal = 0;
		int count = 1;		// Counter to count to position while traversing linked list
		Node* beforeCurr = head_;
		for (Node* curr = head_->next; curr != NULL; count++)
		{ // Traversal of linked list to position
			if (count == pos)
			{ // If count == pos, position reached
				beforeCurr->next = curr->next;		// Points the next node of the node before the node at the position originally to the node after that
				deletedVal = curr->data;			// Assigns value of the node originally at the position into the deleted value
				delete curr;						// Deletes node orignally at the position
				return deletedVal;					// Returns deleted node's value
			}
			beforeCurr = curr;
			curr = curr->next;
		}

	}
}

size_t LinkedList::size()
{
	size_t theSize = 0;

	if (head_ == NULL)
		return theSize;			// If there are no node's (head_ == NULL), return 0

	Node* curr = head_;
	while (curr->next != NULL)
	{ // Traversing to the end of the linekd list from the start
		theSize++;				// Keeps track of linked list's size
		curr = curr->next;
	}
    return theSize + 1;			// Returns the size of the linked list
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() : front_(NULL), back_(NULL)		// Initialise front_ and back_ as NULL
{
}

Queue::~Queue()
{  
	if (size() != 0)
	{ // Checks if there is still undeleted nodes
		Node* toDelete = front_;	// Initialises toDelete as front_ 
		while (toDelete != NULL)
		{ // Traverses the queue and deletes each node till it reaches the end
			Node* nextToDelete = toDelete->next;
			delete toDelete;
			toDelete = nextToDelete;
		}
	}
}

void Queue::enqueue(int data)
{   
	Node* newNode = new Node(data);
	if (front_ == NULL)
	{ // If queue is empty (front_ == NULL),
		// front_ and back_ will be initialised as newNode
		front_ = newNode;	
		back_ = newNode;
	}
	else
	{ // If node is not empty
		back_->next = newNode;		// back_->next points to the new Node
		back_ = newNode;			// back_ points to the new Node
	}
}

int Queue::dequeue()
{
	int dequeuedData = 0;
	if (front_ == NULL) // If queue is empty (front_ == NULL), return 0
		return dequeuedData;
	else if (front_ == back_)
	{ // If front_ and back_ point to the same node (One node left)
		Node* curr = front_;		// curr points to the node to be deleted
		front_ = front_->next;		// front_ points to NULL
		back_ = front_;				// back_ points to NULL
		dequeuedData = curr->data;	// the dequeuedData is assigned the data of the node to be deleted
		delete curr;				// Deletes the node
		return dequeuedData;		// Returns the value of the dequeued node
	}
	// If queue isn't empty and front_ != back_
	Node* curr = front_;			// curr points to the node to be deleted
	front_ = front_->next;			// front_ points to the node after the ndoe to be deleted
	dequeuedData = curr->data;		// The dequeuedData is assigned the data of the node to be deleted
	delete curr;					// Deleted the node
	return dequeuedData;			// Returns the value of the node dequeued
}

size_t Queue::size()
{
	size_t sizeOfQueue = 0;
	if (front_ == NULL) // If queue is empty (front_ == NULL), return 0
		return sizeOfQueue;
	
	Node* curr = front_;
	while (curr->next != NULL)
	{ // Traverses to the end of the queue
		sizeOfQueue++;		// Keeps track of number of nodes in queue
		curr = curr->next;
	}
	return sizeOfQueue + 1; // Returns size of the queue
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack() : top_(NULL)		// Initialises top_ to NULL 
{
}

Stack::~Stack()
{
	if (size() != 0)
	{ // If the stack still has some undeleted nodes
		Node* toDelete = top_;
		while (toDelete != NULL)
		{ // Traverses to the end of the stack, deleting each node it passes
			Node* nextToDelete = toDelete->next;
			delete toDelete;
			toDelete = nextToDelete;
		}
	}
}

void Stack::push(int data)
{
	Node* newNode = new Node(data);
	if (top_ == NULL)		// If stack is empty (top_ == NULL), top_ will point to the newNode
		top_ = newNode;
	else
	{ // If stack is not empty
		newNode->next = top_;	// Points newNode->next to top_
		top_ = newNode;			// Points top_ to newNode
								// This makes it such that the newNode->next points to the node before it, but has top_ pointing to it
	}
}

int Stack::pop()
{
	int poppedVal = 0;
	if (top_ == NULL)	// If stack is empty (top_ == NULL), return 0
		return poppedVal;
	
	Node* curr = top_;		
	top_ = top_->next;			// points top_ to the previous node
	poppedVal = curr->data;		// assigns the value of the popped node to poppedVal
	delete curr;				// Deleted the node 

    return poppedVal;			// Returns the value of the popped node
}

size_t Stack::size()
{
	size_t sizeOfStack = 0;
	if (top_ == NULL)			// If stack is empty (top_ == NULL), return 0 
		return sizeOfStack;

	Node* curr = top_;
	while (curr->next != NULL)
	{ // Traverses to the end of the stack
		sizeOfStack++;			// Keeps track of number of nodes in stack
		curr = curr->next;
	}
	return sizeOfStack + 1;		// Returns the size of stack
}



// Balanced parenthesis
bool Brackets(const string& input)
{
	int stringLength = input.size();
	Stack bracket;
	for (int bracketCheck = 0; bracketCheck < stringLength; bracketCheck++)
	{ // Traverses to the end of the string
		if ((input[bracketCheck] == '(') || (input[bracketCheck] == '{')
			|| (input[bracketCheck] == '[') || (input[bracketCheck] == '<'))
			bracket.push(input[bracketCheck]); // Checks if it is an opening bracket, if it is, push into stack
		else if ((input[bracketCheck] == ')') || (input[bracketCheck] == '}')
			|| (input[bracketCheck] == ']') || (input[bracketCheck] == '>'))
		{ // Checks if it is a closing bracket
			if (bracket.size() == 0)
				return false; // If size of stack is 0, but there is still a closing bracket, return false
			switch (input[bracketCheck])
			{
			case ')':
				if (bracket.pop() != 40) // Checks for ascii number of '(', if it isn't, return false
					return false;
				break;
			case '}':
				if (bracket.pop() != 123) // Checks for ascii number of '{', if it isn't, return false
					return false;
				break;
			case ']':
				if (bracket.pop() != 91) // Checks for ascii number of '[', if it isn't, return false
					return false;
				break;
			case '>':
				if (bracket.pop() != 60) // Checks for ascii number of '<', if it isn't, return false
					return false;
				break;
			}
		}
	}
	if (bracket.size() == 0) // If at the end, the size of stack is 0, return true
		return true;
	else					// If size is not 0, return false
		return false;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
	for (unsigned int queryCount = 0; queryCount < queries.size(); queryCount++)
	{ // Traverses to the end of the queries
		unsigned int result = 0;
		for (unsigned int checker = 0; checker < data.size(); checker++)
		{ //Traverses to the end of the data
			if (queries[queryCount] == data[checker])
				result++; // If Query number is equal to data number, number of occurance for the number increases by 1
		}
		results.push_back(result); // Pops the number of occurances into the result vector
	}
}