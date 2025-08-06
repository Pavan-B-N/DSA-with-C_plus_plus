// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution
{
public:
    // arr : given array
    // k : find kth smallest element
    int kthSmallest(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k > n)
        {
            return -1;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

        while (k > 1)
        {
            minHeap.pop();
            k--;
        }

        return minHeap.top();
    }
};

// Time Complexity: O(nlogk)
// Space Complexity: O(k)
class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k > n)
        {
            return -1;
        }
        priority_queue<int> maxHeap;

        for (int ele : arr)
        {
            if (maxHeap.size() < k)
            {
                maxHeap.push(ele);
            }
            else if (maxHeap.top() > ele)
            {
                maxHeap.pop();
                maxHeap.push(ele);
            }
        }

        return maxHeap.top();
    }
};