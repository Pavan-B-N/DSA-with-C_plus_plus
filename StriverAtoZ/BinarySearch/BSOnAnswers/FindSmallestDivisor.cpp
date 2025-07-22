// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include <vector>
#include <algorithm>
using namespace std;
// . Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

class Solution
{
public:
    // smallest divisor
    // result= sum(arr[i]/divisor,....)
    // result <= threshold
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            bool isPossible = canDivideWithinThreshold(nums, threshold, mid);
            if (isPossible)
            {
                end = mid - 1; // ans=mid
            }
            else
            {
                start = mid + 1;
            }
        }
        return start; // ans
    }
    bool canDivideWithinThreshold(vector<int> &nums, int maxThreshold, int divisor)
    {
        // threshold=17, (1+2+5+9) if the divisor is 1.
        int threshold = 0;
        for (int ele : nums)
        {
            threshold += (ceil((double)ele / divisor));
        }
        return threshold <= maxThreshold;
    }
};