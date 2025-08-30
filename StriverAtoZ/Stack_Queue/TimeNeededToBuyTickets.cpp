// https://leetcode.com/problems/time-needed-to-buy-tickets/
#include <vector>
#include <queue>
using namespace std;

// O(n × tickets[k]).
// O(n) space.
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    queue<int> q; // index
    int time = 0;
    // first push all the elements index queue;
    for (int i = 0; i < tickets.size(); i++)
    {
        q.push(i);
    }

    while (!q.empty() && tickets[k] > 0)
    {
        int index = q.front();
        q.pop();
        tickets[index]--;
        time++;
        if (tickets[index] > 0)
        {
            q.push(index);
        }
    }

    return time;
}

// O(n) time and O(1) extra space
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int time = 0;
    for (int i = 0; i < tickets.size(); i++)
    {
        if (i <= k)
        {
            // left part of k
            // [3,5,4,3] k=2
            // left part  = [3,5,4]
            // each individual can come into queue less than or equal to k times.
            // 3 < 4, so it can take upto 3s
            // 5>4 but still k=4 get a chance just by 4times traversal of 5
            time += min(tickets[i], tickets[k]);
        }
        else
        {
            // right part of k
            time += min(tickets[i], tickets[k] - 1);
        }
    }
    return time;
}