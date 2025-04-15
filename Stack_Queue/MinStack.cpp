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

class MinStack
{
public:
    stack<long long int> st; // Use long long to prevent overflow issues
    long long int minElement;

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minElement = val;
        }
        else
        {
            if (val < minElement)
            {
                st.push((long long)2 * val - minElement);
                minElement = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.top() < minElement)
        {
            // Decode the minimum element by restoring the previous min
            minElement = 2 * minElement - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (st.empty())
            return -1; // Or throw exception

        if (st.top() < minElement)
        {
            return minElement;
        }
        return (int)st.top();
    }

    int getMin()
    {
        return minElement;
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