// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
/*
You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
*/

// Time: O(n log n +  O(n*maxDeadline)) (due to sorting)
// to optimize this we need to use DSU = Disjoint Set Union, Competitive programming 
// Space: O(maxDeadline) for the slot array
// TLE
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        int n = deadline.size();
        vector<pair<int, int>> jobs; // {profit,deadline

        // Pair each job's profit with its deadline
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({profit[i], deadline[i]});
        }

        // Sort jobs by descending profit
        sort(jobs.rbegin(), jobs.rend()); // highest profit first

        // Find the maximum deadline to size the slots
        int maxDeadline = *max_element(deadline.begin(), deadline.end());

        vector<bool> slot(maxDeadline + 1, false); // index 0 unused
        int countJobs = 0, maxProfit = 0;

        for (int i = 0; i < n; i++)
        {
            int currProfit = jobs[i].first;
            int currDeadline = jobs[i].second;

            // Find a free slot from currDeadline down to 1
            for (int j = currDeadline; j >= 1; j--)
            {
                if (!slot[j])
                {
                    slot[j] = true;
                    countJobs++;
                    maxProfit += currProfit;
                    break;
                }
            }
        }

        return {countJobs, maxProfit};
    }
};
