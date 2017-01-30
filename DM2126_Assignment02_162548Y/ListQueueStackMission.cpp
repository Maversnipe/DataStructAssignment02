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
	Node newNode(data);
	Node* curr = head_;
	if (size() == 0)
		head_ = &newNode;
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = &newNode;
	}
}

int LinkedList::pop_front()
{
	int deletedVal = 0;

	if (size() == 0)
		return deletedVal;

	Node* curr = head_;
	head_ = head_->next;
	deletedVal = curr->data;
	curr = NULL;
	delete curr;

    return deletedVal;
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
}

int LinkedList::pop_at(int pos)
{
    return 0;
}

size_t LinkedList::size()
{
    return 0;
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