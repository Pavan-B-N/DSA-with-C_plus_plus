// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
// Time Complexity: O(nlogn+klogk)
// Space Complexity: O(n+k)
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> topKSumPairs(const vector<int> &a, const vector<int> &b, int k)
    {
        int n = a.size();
        vector<int> A = a, B = b;
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> visited;
        vector<int> res;

        pq.push({A[0] + B[0], {0, 0}});
        visited.insert({0, 0});

        while ((int)res.size() < k && !pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            res.push_back(sum);

            // (i+1, j)
            if (i + 1 < n && visited.find({i + 1, j}) == visited.end())
            {
                visited.insert({i + 1, j});
                pq.push({A[i + 1] + B[j], {i + 1, j}});
            }
            // (i, j+1)
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
            {
                visited.insert({i, j + 1});
                pq.push({A[i] + B[j + 1], {i, j + 1}});
            }
        }

        return res;
    }
};