// https://leetcode.com/problems/last-stone-weight/
#include <queue>
#include <vector>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(n) — for the heap.
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap;
        for (int ele : stones)
        {
            maxHeap.push(ele);
        }

        while (maxHeap.size() > 1)
        {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (x - y > 0)
                maxHeap.push(x - y);
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};