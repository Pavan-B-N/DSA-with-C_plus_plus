// https://leetcode.com/problems/max-consecutive-ones/
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxOnes = 0, currentCount = 0;

        for (int num : nums)
        {
            if (num == 1)
            {
                currentCount++;
                maxOnes = max(maxOnes, currentCount);
            }
            else
            {
                currentCount = 0;
            }
        }

        return maxOnes;
    }
};
