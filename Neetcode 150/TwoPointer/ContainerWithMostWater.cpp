// https://leetcode.com/problems/container-with-most-water/description/
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int maxWater = 0;
        while (i < j)
        {
            int altitude = min(height[i], height[j]);
            int width = (j - i);
            int waterStorage = altitude * width;
            maxWater = max(maxWater, waterStorage);
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxWater;
    }
};