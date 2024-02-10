#include <iostream>
#include <stack>

class QueueUsingStack {
private:
    std::stack<int> stack1; // Original stack (acts like a queue)
    std::stack<int> stack2; // Helper stack to make stack as a queue

public:
    void enqueue(int value) {
        while (!stack1.empty()) {
            int element = stack1.top();
            stack1.pop();
            stack2.push(element);
        }

        stack1.push(value);

        while (!stack2.empty()) {
            int element = stack2.top();
            stack2.pop();
            stack1.push(element);
        }
    }

    int dequeue() {
        int front = stack1.top();
        stack1.pop();
        return front;
    }

    int peek() {
        return stack1.top();
    }

    void display() {
        while (!stack1.empty()) {
            int element = stack1.top();
            std::cout << element << " ";
            stack2.push(element);
            stack1.pop();
        }

        std::cout << std::endl;

        while (!stack2.empty()) {
            int element = stack2.top();
            stack1.push(element);
            stack2.pop();
        }
    }
};

int main() {
    QueueUsingStack queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    // Display the elements in the queue
    queue.display();

    // Dequeue an element
    queue.dequeue();

    // Display the elements after dequeue operation
    queue.display();

    return 0;
}
