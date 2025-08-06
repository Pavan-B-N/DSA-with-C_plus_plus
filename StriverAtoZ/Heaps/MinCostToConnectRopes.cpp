// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
/*
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 
Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. Cost of this operation 2 + 3 = 5. 
2) Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9 + 6 =15. Total cost is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we get two rope of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.
*/
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
        int totalCost = 0;
        while (minHeap.size() > 1)
        {
            int top1 = minHeap.top();
            minHeap.pop();
            int top2 = minHeap.top();
            minHeap.pop();
            int cost = top1 + top2;
            totalCost += cost;
            minHeap.push(cost);
        }
        return totalCost;
    }
};