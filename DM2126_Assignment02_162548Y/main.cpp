#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::vector;


bool Brackets(const string& input);
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results);

double timeTaken(clock_t startTime);

// this ensures that _CrtDumpMemoryLeaks() is called after main() and right before program terminates
struct AtExit
{
    ~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

int main()
{
    // This sets the boolean values to be represented in a textual format.
    cout << std::boolalpha;

    // Start the clock
    clock_t start = clock();

    // part 1
    cout << "Part 1" << endl;
	LinkedList ll_;
	ll_.size();
	ll_.push_front(11);
	ll_.push_front(12);
	ll_.push_front(13);
	ll_.push_front(14);
	ll_.push_front(15);
	cout << ll_.pop_at(3) << endl;
	ll_.pop_back();
	ll_.pop_at(1);
	ll_.pop_at(0);
	ll_.pop_at(-1);
	cout << ll_.pop_at(1) << endl;
	cout << ll_.pop_at(-10000) << endl;
	cout << endl;

    // part 2
    cout << "Part 2" << endl;
    Queue q;
	q.enqueue(20);
	q.enqueue(20);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
    cout << q.size() << endl;
    cout << endl;

    // part 3
    cout << "Part 3" << endl;
    Stack s;
    s.push(46);
    s.push(8);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << endl;

    // part 4
    cout << "Part 4" << endl;
    const char* input = "()()[]<>{{[{}]}}";
    cout << Brackets(input) << endl;
    cout << endl;

    // part 5
    cout << "Part 5" << endl;
    int dataArray[] = {1, 1, 1, 1, 9, 10, 1, 4};
    int queryArray[] = {1, 4, 1, 3, 10};

    vector<int> data(dataArray, dataArray + sizeof(dataArray) / sizeof(dataArray[0]));
    vector<int> queries(queryArray, queryArray + sizeof(queryArray) / sizeof(queryArray[0]));
    vector<unsigned int> results;
    QueryMachine(data, queries, results);
    for (size_t i = 0; i < results.size(); ++i)
    {
        cout << results[i] << " ";
    }
    cout << endl;

    cout << "Time taken to run the above code is " << timeTaken(start) << "ms" << endl;

    return 0;
}

// If you are curious, this calculates the time taken between the start time and the time that this function is called.
// The return value is in milliseconds (ms)
double timeTaken(clock_t startTime)
{
    return (clock() - startTime) / (double)(CLOCKS_PER_SEC/1000);
}

