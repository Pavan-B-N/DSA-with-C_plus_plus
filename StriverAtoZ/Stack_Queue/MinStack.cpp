// https://leetcode.com/problems/min-stack/description/
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

// Auxiliary Space: o(1)
// push = (2*curr - min)
// pop = (2*min - curr)
// The trick is to encode and decode the minimum values using simple math.
// When a new minimum is pushed, we store a modified value instead of the real value. This encoded value helps us to:

// Detect if the top is a modified value (to know if it was a min).

// Restore the previous min when popping.
// Modified Value = 2 * val - minElement
// minElement = 2 * minElement - encodedValue

class MinStack
{
public:
    stack<long long int> st;  // Use long long to prevent overflow issues, stores modified value
    long long int minElement; // stores min and top in some cases

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
                st.push((long long)2 * val - minElement); // we need to come back at pop, so we need to preserve the previous min using maths
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
        if (st.top() < minElement) // hence its a modified value
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

        if (st.top() < minElement) // so top refering to modified value, so top is minElement
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

// Auxiliary Space: O(2N). because we are using extra stack to store minimum elements
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
        if (!minStack.empty() && minStack.top() == originalStack.top())
        {
            minStack.pop();
        }
        originalStack.pop();
    }
    
    int getMin()
    {
        return minStack.top();
    }
};