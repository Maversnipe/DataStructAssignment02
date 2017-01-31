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
 *  \author    <John Doe>
 *  \date      2015 
 *  \note      <Admin ID>
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() : head_(NULL)
{
}

LinkedList::~LinkedList()
{ 
	delete head_;
}

void LinkedList::push_front(int data)
{
	Node newNode(data);			// Create a new node with the new data inside
	if (size() == 0)
	{ // If linked list size is 0, head pointer points to the new node
		head_ = &newNode; 
	}
	else
	{ // If linked list size is not 0, point head pointer to the new node and 
		// point the new node's next pointer to the original first node
		Node* curr = head_;		// Create a node pointer pointing at the head pointer
		head_ = &newNode;		// Points head pointer to the new node
		newNode.next = curr;	// Uses the new node's next pointer to point to the original first node
	}
}

void LinkedList::push_back(int data)
{
	Node newNode(data);			// Create a new node with the new data inside
	Node* curr = head_;			// Create a new node pointer, curr, which points to where head_ is pointing
	if (size() == 0)			
		head_ = &newNode;		// If size() is 0, head_ pointer will just point to new node
	else
	{ // If size() is not 0
		while (curr->next != NULL) // Loops to end of linked list
			curr = curr->next;
		curr->next = &newNode;	// Points the last node's next pointer to the new node
	}
}

int LinkedList::pop_front()
{
	int deletedVal = 0;			// Create an int to store the value of the deleted node

	if (size() == 0)	
		return deletedVal;		// Returns 0 if size() is 0

	Node* curr = head_;			// Create a node pointer, curr, which points to where head_ is pointing
	head_ = head_->next;		// Points head pointer to the next node
	deletedVal = curr->data;	// Put the value of the node to be popped into deletedVal
	curr = NULL;				// Make curr pointer become NULL
	delete curr;				// Delete the curr Pointer

    return deletedVal;			// Returns the popped node's value
}

int LinkedList::pop_back()
{    
	int deletedVal = 0;
	
	if (size() == 0)
		return deletedVal;

	Node* curr = head_->next;
	Node* beforeCurr = head_;
	while (curr->next != NULL)
	{
		beforeCurr = curr;
		curr = curr->next;
	}
	deletedVal = curr->data;
	beforeCurr = NULL;
	curr = NULL;
	delete beforeCurr;
	delete curr;

    return deletedVal;
}

void LinkedList::insert_at(int pos, int data)
{ 
	if (pos <= 0)
	{
		push_front(data);
	}
	else if (pos > (size() - 1))
	{
		push_back(data);
	}
	else if (pos < size())
	{
		Node* beforeCurr = head_;
		Node* curr = head_->next;
		Node newNode(data);

		for (int placeToBeInserted = 1; placeToBeInserted < pos; placeToBeInserted++)
		{
			beforeCurr = curr;
			curr = curr->next;
		}

		beforeCurr->next = &newNode;
		newNode.next = curr;
	}
}

int LinkedList::pop_at(int pos)
{
	if (pos <= 0)
	{
		return pop_front();
	}
	else if (pos > (size() - 1))
	{
		return pop_back();
	}
	else if (pos < size())
	{
		int deletedVal = 0;
		Node* beforeCurr = head_;
		Node* curr = head_->next;

		for (int placeToBeInserted = 1; placeToBeInserted < pos; placeToBeInserted++)
		{
			beforeCurr = curr;
			curr = curr->next;
		}

		deletedVal = curr->data;
		curr = NULL;
		beforeCurr->next = NULL;
		delete beforeCurr->next;
		delete curr;

		return deletedVal;
	}
}

size_t LinkedList::size()
{
	size_t theSize = 0;
	Node* curr = head_;
	while (curr->next)
	{
		theSize++;
		curr = curr->next;
	}
    return theSize;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() 
{
}

Queue::~Queue()
{   
}

void Queue::enqueue(int data)
{   
}

int Queue::dequeue()
{
    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{

}

Stack::~Stack()
{
}

void Stack::push(int data)
{
}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
    return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
}