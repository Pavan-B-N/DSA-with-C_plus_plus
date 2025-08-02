#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort()
{
    // Your code here
    vector<int> temp;
    while (!s.empty())
    {
        temp.push_back(s.top());
        s.pop();
    }

    std::sort(temp.begin(), temp.end());

    for (int ele : temp)
    {
        s.push(ele);
    }
}

void insertInSortedOrder(stack<int> &s, int x)
{
    if (s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insertInSortedOrder(s, x);
    s.push(temp);
}

void SortedStack::sort()
{
    if (s.empty())
        return;

    int top = s.top();
    s.pop();
    sort();
    insertInSortedOrder(s, top);
}
