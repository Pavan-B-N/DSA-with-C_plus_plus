
// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
#include <iostream>
using namespace std;

// Node structure for the stack
struct StackNode
{
    int data;
    StackNode *next;

    StackNode(int x)
    {
        data = x;
        next = nullptr;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    MyStack() { top = NULL; }

    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        int data = top->data;
        top = top->next;
        return data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};
