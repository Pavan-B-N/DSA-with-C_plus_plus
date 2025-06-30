// https://leetcode.com/problems/min-stack/
#include <stack>
#include <iostream>
#include <climits>
using namespace std;

class MinStack
{
public:
    stack<long long int> st; // stores modified value
    long long int minElement;
    MinStack()
    {
        minElement = INT_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minElement = val;
            return;
        }

        if (val < minElement)
        {
            long long int modifiedVal = (long long int)2 * val - minElement;
            st.push(modifiedVal);
            minElement = val;
        }
        else
        {
            st.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }

        if (st.top() < minElement)
        {
            minElement = 2 * minElement - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }

        if (st.top() < minElement)
        {
            return minElement;
        }

        return st.top();
    }

    int getMin()
    {
        return minElement;
    }
};
