#include <iostream>
using namespace std;

const int CAPACITY = 100; // Maximum size of the queue

class CircularQueue {
private:
    int arr[CAPACITY];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    // push
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow, Cannot perform enqueue operation\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % CAPACITY;
        }

        arr[rear] = value;
    }

    //pop
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow, Cannot perform dequeue operation\n";
            return;
        }

        cout << "Dequeued " << arr[front] << " from the queue\n";

        if (front == rear) {
            front = rear = -1; // Reset the queue when the last element is dequeued
        } else {
            front = (front + 1) % CAPACITY;
        }
    }
    //frony
    int peek() {
        if (isEmpty()) {
            cout << "The queue is empty\n";
            return -1; // Assuming -1 represents an empty queue
        }

        return arr[front];
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % CAPACITY == front;
    }

    void display() {
        if (isEmpty()) {
            cout << "The queue is empty\n";
            return;
        }

        cout << "Front -> ";
        for (int i = front; i != rear; i = (i + 1) % CAPACITY) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << " <- Rear\n";
    }
};

int main() {
    CircularQueue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    cout << "Front element: " << myQueue.peek() << endl;

    return 0;
}
