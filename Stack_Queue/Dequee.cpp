#include <iostream>
using namespace std;

const int INITIAL_CAPACITY = 5; // Initial capacity of the deque

class MyDeque {
private:
    int* arr;
    int front, rear, capacity;

public:
    MyDeque() {
        arr = new int[INITIAL_CAPACITY];
        front = rear = -1;
        capacity = INITIAL_CAPACITY;
    }

    ~MyDeque() {
        delete[] arr;
    }

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        int index = 0;
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            newArr[index++] = arr[i];
        }
        newArr[index] = arr[rear];

        front = 0;
        rear = index;
        capacity = newCapacity;

        delete[] arr;
        arr = newArr;
    }

    void push_front(int value) {
        if ((front - 1 + capacity) % capacity == rear) {
            // Deque is full, resize the array
            resize();
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
    }

    void push_back(int value) {
        if ((rear + 1) % capacity == front) {
            // Deque is full, resize the array
            resize();
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
    }

    void pop_front() {
        if (isEmpty()) {
            cout << "Deque underflow, Cannot perform pop_front operation\n";
            return;
        }

        cout << "Popped " << arr[front] << " from the front of the deque\n";

        if (front == rear) {
            // Reset the deque when the last element is popped
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    void pop_back() {
        if (isEmpty()) {
            cout << "Deque underflow, Cannot perform pop_back operation\n";
            return;
        }

        cout << "Popped " << arr[rear] << " from the back of the deque\n";

        if (front == rear) {
            // Reset the deque when the last element is popped
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }
    }

    int peek_front() {
        if (isEmpty()) {
            cout << "The deque is empty\n";
            return -1; // Assuming -1 represents an empty deque
        }

        return arr[front];
    }

    int peek_back() {
        if (isEmpty()) {
            cout << "The deque is empty\n";
            return -1; // Assuming -1 represents an empty deque
        }

        return arr[rear];
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "The deque is empty\n";
            return;
        }

        cout << "Front -> ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << " <- Rear\n";
    }
};

int main() {
    MyDeque myDeque;

    myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_front(5);
    myDeque.push_front(15);

    myDeque.display();

    myDeque.pop_back();
    myDeque.pop_front();

    myDeque.display();

    cout << "Front element: " << myDeque.peek_front() << endl;
    cout << "Rear element: " << myDeque.peek_back() << endl;

    return 0;
}
