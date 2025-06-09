// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            int probableThreshold = getThreshold(nums, mid);
            if (probableThreshold <= threshold)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return start;
    }

    int getThreshold(vector<int> &nums, int divisor)
    {
        int threshold = 0;
        for (auto ele : nums)
        {
            threshold += ceil(double(ele) / double(divisor));
        }

        return threshold;
    }
};