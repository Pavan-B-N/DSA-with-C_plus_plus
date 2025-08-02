// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Can you solve it without sorting?
#include <queue>
#include <vector>
using namespace std;

// time complexity = o(n log k )
// space complexity = o(n)
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
            else if (ele > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(ele);
            }
        }

        return minHeap.top();
    }
};

// O(n * logn)
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

        priority_queue<int> maxHeap;
        for (int ele : nums)
        {
            maxHeap.push(ele);
        }

        while (k > 1)
        {
            maxHeap.pop();
            k--;
        }
        return maxHeap.top();
    }
};

// with the help of sorting
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

        sort(nums.begin(), nums.end());
        return nums[n - k];
    }
};
