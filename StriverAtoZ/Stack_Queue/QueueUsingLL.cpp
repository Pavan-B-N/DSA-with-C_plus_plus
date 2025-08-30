// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

#include <iostream>
using namespace std;

// Function to push an element into the queue.
void MyQueue::push(int x)
{
    QueueNode *newNode = new QueueNode(x);
    if (!front)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    if (!front)
        return -1;
    int data = front->data;
    if (front == rear)
    {
        front = rear = nullptr;
    }
    else
    {
        front = front->next;
    }
    return data;
}

class QueueNode
{
public:
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyQueue
{
public:
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};