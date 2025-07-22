// https://leetcode.com/problems/longest-consecutive-sequence/
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // O(nlogn)
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int currLen = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                continue; // Skip duplicates
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                currLen++;
            }
            else
            {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};

class Solution
{
public:
    // Time complexity: O(2n)
    // Space complexity: O(n) due to unordered_set

    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> hashSet(nums.begin(), nums.end());

        int maxLen = 0;
        for (auto ele : hashSet)
        {
            // last occurance
            if (hashSet.find(ele + 1) == hashSet.end())
            {
                int currLen = 0;
                // it can  got up to O(n) in the worst case overall
                while (hashSet.count(ele))
                {
                    currLen++;
                    ele--;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};