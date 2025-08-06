// https://leetcode.com/problems/task-scheduler/
/*
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

*/
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freqMap; // {char,freq}
        for (char task : tasks)
        {
            freqMap[task]++;
        }

        priority_queue<int> maxHeap; // freq
        for (auto it : freqMap)
        {
            maxHeap.push(it.second);
        }

        queue<pair<int, int>> cooldownQueue; //{freq,available_time}
        int time = 0;
        while (!maxHeap.empty() || !cooldownQueue.empty())
        {
            time++;

            // need to check if someone in the queu and push to maxHeap
            if (!cooldownQueue.empty() && cooldownQueue.front().second == time)
            {
                int taskFreq = cooldownQueue.front().first;
                cooldownQueue.pop();
                maxHeap.push(taskFreq);
            }

            if (!maxHeap.empty())
            {
                int taskFreq = maxHeap.top();
                maxHeap.pop();
                if (taskFreq > 1)
                {
                    cooldownQueue.push({taskFreq - 1, time + n + 1});
                }
            }
        }

        return time;
    }
};