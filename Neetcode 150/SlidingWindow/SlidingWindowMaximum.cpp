// https://leetcode.com/problems/sliding-window-maximum/
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> dq; // stores indices

        // building first window
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++)
        {
            res.push_back(nums[dq.front()]);

            // remove not part of window
            while (!dq.empty() && (i - dq.front()) >= k)
            {
                dq.pop_front();
            }

            // remove lesser elements
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};