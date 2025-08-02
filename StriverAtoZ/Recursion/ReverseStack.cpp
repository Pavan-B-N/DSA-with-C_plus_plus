// https://www.geeksforgeeks.org/problems/reverse-a-stack/1
#include <vector>
#include <stack>
using namespace std;

// using recursion = o(n^2)
// using extra stack = O(n)
// O(n^2)
class Solution
{
public:
    void Reverse(stack<int> &St)
    {
        if (St.empty())
            return;

        int top = St.top();
        St.pop();

        Reverse(St);

        insertAtBottom(St, top);
    }

    void insertAtBottom(stack<int> &s, int x)
    {
        if (s.empty())
        {
            s.push(x);
            return;
        }

        // empties stack
        int top = s.top();
        s.pop();

        insertAtBottom(s, x);

        s.push(top);
    }
};

// O(n)
class Solution
{
public:
    void Reverse(stack<int> &St)
    {
        stack<int> temp;

        while (!St.empty())
        {
            temp.push(St.top());
            St.pop();
        }

        St = temp; // reversed
    }
};
