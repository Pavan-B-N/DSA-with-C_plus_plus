// https://leetcode.com/problems/kth-largest-element-in-a-stream//
#include <queue>
#include <vector>
using namespace std;

// Time: O(log k) per add() call (heap insertion/removal).
// Space: O(k) — only k elements are kept in the heap.
class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (auto ele : nums)
        {
            add(ele);
        }
    }

    // log(k)
    int add(int val)
    {
        // Always maintain the k largest elements in the min-heap.
        if (minHeap.size() < k)
        {
            minHeap.push(val);
        }
        else if (val > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top(); //// kth largest element
    }
};
