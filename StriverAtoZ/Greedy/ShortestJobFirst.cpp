/*
You are given:
n jobs, and
Each job has a burst time (i.e., how long it takes to complete).

Using the Shortest Job First (SJF) scheduling algorithm (non-preemptive), you need to calculate the average waiting time for all jobs.

The waiting time for a job = total time it waited before starting.
Input:
n = 5
burst[] = [4, 2, 1, 3, 3]

Sorted burst[] = [1, 2, 3, 3, 4] // because SJF picks the smallest job first

Waiting Times:
- Job 1 (1 unit) → Wait = 0
- Job 2 (2 units) → Wait = 1
- Job 3 (3 units) → Wait = 1 + 2 = 3
- Job 4 (3 units) → Wait = 1 + 2 + 3 = 6
- Job 5 (4 units) → Wait = 1 + 2 + 3 + 3 = 9

Total Wait = 0 + 1 + 3 + 6 + 9 = 19
Average Wait = 19 / 5 = **3**

*/
// https://www.geeksforgeeks.org/problems/shortest-job-first/1
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &bt)
    {

        long long waitTime = 0;
        long long totalTime = 0;
        sort(bt.begin(), bt.end());

        for (int i = 0; i < bt.size() - 1; i++)
        {
            waitTime += bt[i];
            totalTime += waitTime;
        }

        return totalTime / bt.size();
    }
};