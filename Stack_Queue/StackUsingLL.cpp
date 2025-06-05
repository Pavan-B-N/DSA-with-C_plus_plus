
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

// Class to implement stack using linked list
class LLStack
{
private:
    StackNode *top;

public:
    LLStack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == nullptr)
            return -1;
        int val = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return val;
    }
};

int main()
{
    LLStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl; // 30
    cout << s.pop() << endl; // 20
    cout << s.pop() << endl; // 10
    cout << s.pop() << endl; // -1
    return 0;
}
