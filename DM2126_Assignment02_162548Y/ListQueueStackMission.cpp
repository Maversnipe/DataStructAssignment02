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
	head_ = NULL;
	delete head_;
}

void LinkedList::push_front(int data)
{
	Node* newNode = new Node(data);			// Create a new node with the new data inside
	if (head_ == NULL)
	{ // If linked list size is 0
		head_ = newNode;					// Point head pointer to newNode
		newNode->next = NULL;
		delete newNode->next;
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
	int deletedVal = 0;
	
	if (head_ == NULL)
		return deletedVal;
	else if (head_->next == NULL)
		return pop_front();

	Node* curr = head_->next;
	Node* beforeCurr = head_;
	while (curr->next != NULL)
	{
		beforeCurr = curr;
		curr = curr->next;
	}
	deletedVal = curr->data;

	beforeCurr->next = NULL;
	delete curr;

    return deletedVal;
}

void LinkedList::insert_at(int pos, int data)
{ 
	if (pos <= 0)
	{
		push_front(data);
	}
	else if ((size_t)pos >= (size()))
	{
		push_back(data);
	}
	else if ((size_t)pos < size())
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
	else if ((size_t)pos > (size() - 1))
	{
		return pop_back();
	}
	else if ((size_t)pos < size())
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
		delete beforeCurr->next;
		beforeCurr->next = NULL;
		delete curr;

		return deletedVal;
	}
}

size_t LinkedList::size()
{
	size_t theSize = 0;

	if (head_ == NULL)
		return theSize;
	else
		theSize = 1;
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