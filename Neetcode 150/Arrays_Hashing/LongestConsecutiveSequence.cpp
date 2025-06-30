// https://leetcode.com/problems/longest-consecutive-sequence/

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// time complexity = O(2n)
class Solution
{
public:
    // o(2n)
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int len = 0;
        for (int ele : hashSet)
        {
            int previousSmaller = ele - 1;
            if (hashSet.find(previousSmaller) == hashSet.end())
            {
                int nextGreater = ele + 1;
                int count = 1;
                // it can  got up to O(n) in the worst case overall
                while (hashSet.count(nextGreater))
                {
                    count++;
                    nextGreater++;
                }
                len = max(len, count);
            }
        }
        return len;
    }
};
// time complexity = O(nlogn)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 0)
        {
            return 0;
        }
        int prev = INT_MIN;
        int count = 0;
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            // skip duplicates
            if (prev == nums[i])
            {
                continue;
            }
            if (prev + 1 == nums[i])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            prev = nums[i];
            len = max(len, count);
        }
        return len;
    }
};