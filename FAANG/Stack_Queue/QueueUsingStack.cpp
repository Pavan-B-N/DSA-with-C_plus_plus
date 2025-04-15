/*
https://leetcode.com/problems/implement-queue-using-stacks/description/

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int ele=s1.top();
            s1.pop();
            s2.push(ele);
        }

        s1.push(x);

        while(!s2.empty()){
            int ele=s2.top();
            s2.pop();
            s1.push(ele);
        }
    }
    
    int pop() {
        int ele=s1.top();
        s1.pop();
        return ele;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */