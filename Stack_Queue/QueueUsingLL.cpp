// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

#include <iostream>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class LLQueue
{
    QueueNode *front, *rear;

    LLQueue()
    {
        front = rear = NULL;
    }

    // Function to push an element into the queue.
    void push(int x)
    {
        QueueNode *newNode = new QueueNode(x);
        // If queue is empty
        if (front == NULL && rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            // If queue is not empty, insert at rear end
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to pop front element from the queue.
    int pop()
    {
        if (front == NULL && rear == NULL)
        {
            return -1;
        }
        int ele = front->data;
        QueueNode *temp = front;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
        delete temp;
        return ele;
    }
};
