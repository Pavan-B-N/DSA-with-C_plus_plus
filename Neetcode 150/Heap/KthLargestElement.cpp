// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <queue>
#include <vector>
using namespace std;

// most optimal
// time complexity = o(n log k )
// space complexity = o(k)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
        {
            return -1;
        }
        // time complexity for maxHeap operations is o(logk)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int ele : nums)
        {
            if (minHeap.size() < k)
            {
                minHeap.push(ele);
            }
            else if (ele >= minHeap.top())
            {
                minHeap.pop();
                minHeap.push(ele);
            }
        }

        return minHeap.top();
    }
};

// time complexity = o(n log n )
// space complexity = o(n )
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n)
        {
            return -1;
        }
        // time complexity for maxHeap operations is o(logn)
        priority_queue<int> maxHeap;
        for (int ele : nums)
        {
            maxHeap.push(ele);
        }

        while (!maxHeap.empty() && k > 1)
        {
            maxHeap.pop();
            k--;
        }

        return maxHeap.top();
    }
};