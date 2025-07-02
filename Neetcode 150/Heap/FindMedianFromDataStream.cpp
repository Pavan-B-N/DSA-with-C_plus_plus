// https://leetcode.com/problems/find-median-from-data-stream/

#include <queue>
#include <vector>
using namespace std;

class MedianFinder
{
private:
    // Max-heap for the smaller half
    priority_queue<int> leftMaxHeap;
    // Min-heap for the larger half
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

public:
    MedianFinder()
    {
    }

    // Time: O(log n)
    void addNum(int num)
    {
        // Step 1: Add to max heap
        leftMaxHeap.push(num);

        // Step 2: Balance heaps by moving the largest from left to right
        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();

        // Step 3: ensure leftMaxHeap.size() >= rightMinHeap.size()
        if (leftMaxHeap.size() < rightMinHeap.size())
        {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    // Time: O(1)
    double findMedian()
    {
        if (leftMaxHeap.size() > rightMinHeap.size())
        {
            return leftMaxHeap.top();
        }
        else
        {
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        }
    }
};