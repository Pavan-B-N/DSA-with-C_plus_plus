/*
Input:
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ?
since it doesn't exist, it is -1.
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// o(2N)
class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> s;
        
        for (int i = n - 1; i >= 0; i--)
        {
            int ele = arr[i];
            while (!s.empty() && s.top() <= ele)
            {
                s.pop();
            }
            if (!s.empty())
            {
                result[i] = s.top();
            }
            s.push(ele);
        }

        return result;
    }
};

/* Naive approach to find next greater element */
// o(n^2)
vector<int> findNGE_naive(int arr[], int n)
{
    vector<int> result(n, -1);

    // Iterate through each element
    for (int i = 0; i < n; ++i)
    {
        // For the current element, search for the next greater element
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] > arr[i])
            {
                // If found, update the result and break
                result[i] = arr[j];
                break;
            }
        }
    }

    return result;
}
