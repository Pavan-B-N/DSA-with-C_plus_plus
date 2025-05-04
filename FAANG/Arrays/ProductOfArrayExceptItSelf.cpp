// https://leetcode.com/problems/product-of-array-except-self/description/
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        // a[i] product except itself =  prefixProduct * suffixProduct
        // find all prefix products and store it in the ans
        ans[0] = 1; // prefix = ans
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * suffixProduct;
            suffixProduct *= nums[i];
        }
        return ans;
    }
};