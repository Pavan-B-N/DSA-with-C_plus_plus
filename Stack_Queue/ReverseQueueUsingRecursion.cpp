#include <iostream>
#include <queue>

using namespace std;

// Utility function to print the queue
void printQueue(queue<long long int> Queue) {
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

// Function to reverse the queue using recursion
void reverseQueue(queue<long long int>& q) {
    // Base case: if the queue is empty or has only one element
    if (q.size() <= 1)
        return;

    // Dequeue current item (from front)
    long long int data = q.front();
    q.pop();

    // Reverse remaining queue
    reverseQueue(q);

    // Enqueue current item (to rear)
    q.push(data);
}

int main() {
    queue<long long int> Queue;
    Queue.push(56);
    Queue.push(27);
    Queue.push(30);
    Queue.push(45);
    Queue.push(85);
    Queue.push(92);
    Queue.push(58);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    cout << "Original queue: ";
    printQueue(Queue);

    reverseQueue(Queue);

    cout << "\nReversed queue: ";
    printQueue(Queue);

    return 0;
}
