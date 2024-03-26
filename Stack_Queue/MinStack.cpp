/*
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack.

Input:
Stack: 18 19 29 15 16
Output: 15
Explanation:
The minimum element of the stack is 15.
*/
#include <iostream>
#include <stack>
using namespace std;

// / Auxiliary Space: o(1)
// push = (2*curr - min)
// pop = (2*min - curr)
class SpecialStackOptimized
{
public:
    stack<int> originalStack;
    int min;
    void push(int ele)
    {
       if(originalStack.empty() || ele>=min ){
            originalStack.push(ele);
       }else{
            originalStack.push(2*ele-min);
            min=ele;
       }
    }

    void pop()
    {
        if(originalStack.empty()){
            cout<<"Stack Underflow";
        }else if(originalStack.top()>min){
            originalStack.pop();
        }else{
            min=2*min-originalStack.top();
            originalStack.pop();
        }
    }
    int getMin()
    {
        return min;
    }
};  

// Auxiliary Space: O(n). because we are using extra stack to store minimum elements
class SpecialStack
{
public:
    stack<int> originalStack;
    stack<int> minStack;

    void push(int ele)
    {
        originalStack.push(ele);
        if (minStack.empty() || minStack.top() >= ele)
        {
            minStack.push(ele);
        }
    }

    void pop()
    {
        int ele = originalStack.top();
        originalStack.pop();
        if (!minStack.empty() && minStack.top() == ele)
        {
            minStack.pop();
        }
    }
    int getMin()
    {
        return minStack.top();
    }
};

int main(int argc, char const *argv[])
{
    // SpecialStack s;
    SpecialStackOptimized s;
    s.push(10);
    s.push(5);
    s.push(80);
    s.push(3);
    s.push(2);
    s.push(2);

    cout << "Min: " << s.getMin() << endl;
    s.pop();
    cout << "Min: " << s.getMin() << endl;
    s.pop();
    cout << "Min: " << s.getMin() << endl;
    s.pop();
    cout << "Min: " << s.getMin() << endl;
    s.pop();
    return 0;
}
