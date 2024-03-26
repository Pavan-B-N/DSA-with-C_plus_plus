/*
Implement a Stack using two queues q1 and q2.
*/
#include <iostream>
#include <queue>

using namespace std;

// Push operation: O(N)
// Pop operation: O(1)
class Stack {
private:
    queue<int> q1, q2;

public:
    // Function to push an element onto the stack.
    void push(int x) {
        // Push x to q2
        q2.push(x);

        // Push all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);

    }

    // Function to pop an element from the stack.
    int pop() {
        if (q1.empty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }

        int top_element = q1.front();
        q1.pop();
        return top_element;
    }

    // Function to return the top element of the stack.
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return q1.front();
    }

    // Function to check if the stack is empty.
    bool empty() {
        return q1.empty();
    }
};

// using only one queue
class StackEfficient {
    queue<int> q;

public:
    void push(int data) {
        int s = q.size();
        q.push(data);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty())
            cout << "No elements\n";
        else
            q.pop();
    }

    int top() {
        return (q.empty()) ? -1 : q.front();
    }

    int size() {
        return q.size();
    }

    bool empty() {
        return q.empty();
    }
};
int main() {
    Stack s;
    // StackEfficient s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element after popping: " << s.top() << endl;

    s.push(4);
    cout << "Top element after pushing: " << s.top() << endl;

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
