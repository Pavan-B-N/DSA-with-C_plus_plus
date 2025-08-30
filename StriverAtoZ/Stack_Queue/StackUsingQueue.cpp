/*
Implement a Stack using  queues
*/
// https://leetcode.com/problems/implement-stack-using-queues/description/

#include <iostream>
#include <queue>
using namespace std;

// Push operation: O(N)
// Pop operation: O(1)
class LLStack
{
private:
    queue<int> q1, q2;
    // q1 acts as stack
    // q2 is temp

public:
    // Function to push an element onto the stack.
    void push(int x)
    {
        // Push x to q2
        q2.push(x);

        // Push all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Function to pop an element from the stack.
    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }

        int top_element = q1.front();
        q1.pop();
        return top_element;
    }

    // Function to return the top element of the stack.
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return q1.front();
    }

    // Function to check if the stack is empty.
    bool empty()
    {
        return q1.empty();
    }
};

// using only one queue
// Push operation: O(N)
// Pop operation: O(1)
class MyStack
{
    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int ele = q.front();
        q.pop();
        return ele;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};
