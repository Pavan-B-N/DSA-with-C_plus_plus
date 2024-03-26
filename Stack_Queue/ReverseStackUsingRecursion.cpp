#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &s, int ele) {
    if (s.empty()) {
        s.push(ele);
        return;
    }

    // Pop all elements from the stack and insert ele at the bottom
    int topEle = s.top();
    s.pop();
    insertAtBottom(s, ele);
    s.push(topEle);
}

// Function to reverse a stack using recursion
void reverseStack(stack<int> &s) {
    if (!s.empty()) {
        // Pop the top element
        int ele = s.top();
        s.pop();
        
        // Reverse the remaining stack
        reverseStack(s);
        
        // Move the top element to the bottom
        insertAtBottom(s, ele);
    }
}

template<typename T>
void displayStack(stack<T> s) { // Pass stack by value
    cout << "-----------" << endl;
    while (!s.empty()) {
        cout <<" | " << s.top() << " | "<<endl; 
        s.pop();
    }
    cout << "-----------" << endl;
    cout << endl;
}   

int main(int argc, char const *argv[])
{
    stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    displayStack(myStack);

    reverseStack(myStack);

    displayStack(myStack);
    return 0;
}
