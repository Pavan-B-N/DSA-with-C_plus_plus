// https://leetcode.com/problems/rank-transform-of-an-array/description/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
// Time: O(n log n) — sorting dominates.
// Space: O(n) — for the copy and the hash map.
//  Sorting is simpler and usually faster in C++
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sorted = arr;           // copy original array
        sort(sorted.begin(), sorted.end()); // O(n log n)

        unordered_map<int, int> rank;
        int r = 1;
        for (int ele : sorted)
        {
            if (!rank.count(ele))
            {
                rank[ele] = r++;
            }
        }

        vector<int> result;
        result.reserve(arr.size());
        for (int ele : arr)
        {
            result.push_back(rank[ele]);
        }
        return result;
    }
};

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        using P = pair<int, int>; // (value, index)
        priority_queue<P, vector<P>, greater<P>> minHeap;

        for (int i = 0; i < arr.size(); i++)
        {
            minHeap.push({arr[i], i});
        }

        vector<int> rank(arr.size());
        int currRank = 0;
        int prevVal = INT_MIN;

        while (!minHeap.empty())
        {
            auto [val, idx] = minHeap.top();
            minHeap.pop();
            if (val != prevVal)
            {
                currRank++;
                prevVal = val;
            }
            rank[idx] = currRank;
        }
        return rank;
    }
};
