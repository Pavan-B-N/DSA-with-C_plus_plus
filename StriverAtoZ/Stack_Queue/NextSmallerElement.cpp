/*
Input: [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
*/
// https://www.naukri.com/code360/problems/next-greater-element_1112581
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> res(n, -1);
    
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }

        if (!s.empty())
        {
            res[i] = s.top();
        }

        s.push(arr[i]);
    }

    return res;
}