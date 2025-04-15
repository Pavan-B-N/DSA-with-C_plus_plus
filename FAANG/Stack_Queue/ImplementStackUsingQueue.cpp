// https://leetcode.com/problems/implement-stack-using-queues/
// Implement Stack using Queues
/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class MyStack {
    queue<int> q1;// acts as stack
    queue<int> q2;// just for temporary
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int ele=q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


 
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