// https://leetcode.com/problems/max-consecutive-ones-iii/
#include <vector>
using namespace std;
/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/
// while = O(2n)
// if = O(n)
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int zeroCount = 0;
        int maxLength = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++)
        {
            if (nums[right] == 0)
            {
                zeroCount++;
            }

            // Shrink the window from the left if zeroCount exceeds k
            // we can replace while with if, because if maxWindow is 5 we don't have to actually care about the window which is os size lesser
            // if(zeroCount > k) = O(n)
            while (zeroCount > k) // = O(2n)
            {
                if (nums[left] == 0)
                {
                    zeroCount--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
