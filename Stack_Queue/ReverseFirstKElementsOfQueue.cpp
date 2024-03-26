#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Function to reverse the first k elements of a queue
void reverseFirstK(queue<int>& q, int k) {
    if (k <= 0 || k > q.size())
        return; // Invalid input or nothing to reverse

    stack<int> s;

    // Push the first k elements into the stack
    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue elements from the stack back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Move the remaining elements to the back of the queue
    for (int i = 0; i < q.size() - k; ++i) {
        q.push(q.front());
        q.pop();
    }
}

// Function to print the queue
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    int k = 3;

    cout << "Original queue: ";
    printQueue(q);

    reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    printQueue(q);

    return 0;
}
