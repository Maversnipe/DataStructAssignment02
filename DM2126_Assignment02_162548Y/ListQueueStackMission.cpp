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
		Node* toDelete = head_;
		while (toDelete)
		{ 
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

	delete curr;
	beforeCurr->next = NULL;

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
		Node* newNode = new Node(data);

		for (int placeToBeInserted = 1; placeToBeInserted < pos; placeToBeInserted++)
		{
			beforeCurr = curr;
			curr = curr->next;
		}

		beforeCurr->next = newNode;
		newNode->next = curr;
	}
}

int LinkedList::pop_at(int pos)
{
	if (head_ == NULL)
		return 0;

	if (pos <= 0)
	{
		return pop_front();
	}
	else
	{
		int deletedVal = 0;
		int count = 1;
		Node* beforeCurr = head_;
		for (Node* curr = head_->next; curr != NULL; count++)
		{
			if (count == pos)
			{
				beforeCurr->next = curr->next;
				deletedVal = curr->data;
				delete curr;
				return deletedVal;
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
		return theSize;

	Node* curr = head_;
	while (curr->next != NULL)
	{
		theSize++;
		curr = curr->next;
	}
    return theSize + 1;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() : front_(NULL), back_(NULL)
{
}

Queue::~Queue()
{  
	if (size() != 0)
	{
		Node* toDelete = front_;
		while (toDelete != NULL)
		{
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
	{
		front_ = newNode;
		back_ = newNode;
	}
	else
	{
		back_->next = newNode;
		back_ = newNode;
	}
}

int Queue::dequeue()
{
	int dequeuedData = 0;
	if (front_ == NULL)
		return dequeuedData;
	else if (front_ == back_)
	{
		Node* curr = front_;
		front_ = front_->next;
		back_ = front_;
		dequeuedData = curr->data;
		delete curr;
		return dequeuedData;
	}


	Node* curr = front_;
	front_ = front_->next;
	dequeuedData = curr->data;
	delete curr;
	return dequeuedData;
}

size_t Queue::size()
{
	size_t sizeOfQueue = 0;
	if (front_ == NULL)
		return sizeOfQueue;
	
	Node* curr = front_;
	while (curr->next != NULL)
	{
		sizeOfQueue++;
		curr = curr->next;
	}
	return sizeOfQueue + 1;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack() : top_(NULL)
{
}

Stack::~Stack()
{
	if (size() != 0)
	{
		Node* toDelete = top_;
		while (toDelete != NULL)
		{
			Node* nextToDelete = toDelete->next;
			delete toDelete;
			toDelete = nextToDelete;
		}
	}
}

void Stack::push(int data)
{
	Node* newNode = new Node(data);
	if (top_ == NULL)
		top_ = newNode;
	else
	{
		newNode->next = top_;
		top_ = newNode;
	}
}

int Stack::pop()
{
	int poppedVal = 0;
	if (top_ == NULL)
		return poppedVal;
	
	Node* curr = top_;
	top_ = top_->next;
	poppedVal = curr->data;
	delete curr;

    return poppedVal;
}

size_t Stack::size()
{
	size_t sizeOfStack = 0;
	if (top_ == NULL)
		return sizeOfStack;

	Node* curr = top_;
	while (curr->next != NULL)
	{
		sizeOfStack++;
		curr = curr->next;
	}
	return sizeOfStack + 1;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
	int stringLength = input.size();
	Stack bracket;
	for (int bracketCheck = 0; bracketCheck < stringLength; bracketCheck++)
	{
		if ((input[bracketCheck] == '(') || (input[bracketCheck] == '{')
			|| (input[bracketCheck] == '[') || (input[bracketCheck] == '<'))
			bracket.push(input[bracketCheck]);
		else if ((input[bracketCheck] == ')') || (input[bracketCheck] == '}')
			|| (input[bracketCheck] == ']') || (input[bracketCheck] == '>'))
		{
			if (bracket.size() == 0)
				return false;
			switch (input[bracketCheck])
			{
			case ')':
				if (bracket.pop() != 40)
					return false;
				break;
			case '}':
				if (bracket.pop() != 123)
					return false;
				break;
			case ']':
				if (bracket.pop() != 91)
					return false;
				break;
			case '>':
				if (bracket.pop() != 60)
					return false;
				break;
			}
		}
	}
	if (bracket.size() == 0)
		return true;
	else
		return false;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
	for (unsigned int queryCount = 0; queryCount < queries.size(); queryCount++)
	{
		unsigned int result = 0;
		for (unsigned int checker = 0; checker < data.size(); checker++)
		{
			if (queries[queryCount] == data[checker])
				result++;
		}
		results.push_back(result);
	}
}