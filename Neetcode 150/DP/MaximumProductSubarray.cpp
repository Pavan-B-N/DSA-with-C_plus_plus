// https://leetcode.com/problems/maximum-product-subarray/description/

#include <vector>
#include <string>
using namespace std;

// intuative
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int prefix = 1;
        int suffix = 1;
        int n = nums.size();
        int maxProd;
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            int currMax = max(prefix, suffix);
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};
// Modified Kadane’s Algorithm for Product Subarray
// not recommended because its theoritical or algo based
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int currMax = nums[0], currMin = nums[0], maxProd = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            int tempMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], currMax * nums[i], currMin * nums[i]});
            currMax = tempMax;

            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};
