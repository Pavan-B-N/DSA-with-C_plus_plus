// https://leetcode.com/problems/task-scheduler/
#include <queue>
#include <vector>
#include <unordered_map>
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