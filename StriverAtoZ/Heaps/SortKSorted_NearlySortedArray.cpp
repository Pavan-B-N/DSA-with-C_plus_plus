// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
#include <queue>
using namespace std;

class Solution
{
public:
    //   Time Complexity: O(n log k)
    // Auxiliary Space: O(k)
    void nearlySorted(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0;
        // k+1 elements
        while (i <= k)
        {
            minHeap.push(arr[i]);
            i++;
        }

        for (int j = 0; j < arr.size(); j++)
        {
            int top = minHeap.top();
            minHeap.pop();
            arr[j] = top;
            if (i < arr.size())
            {
                minHeap.push(arr[i++]);
            }
        }
    }
};