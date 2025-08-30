// https://leetcode.com/problems/trapping-rain-water/description/
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int maxWater = 0;
        int leftMax = 0;
        int rightMax = 0;
        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            if (leftMax < rightMax)
            {
                maxWater += (leftMax - height[i]);
                i++;
            }
            else
            {
                maxWater += (rightMax - height[j]);
                j--;
            }
        }
        return maxWater;
    }
};
