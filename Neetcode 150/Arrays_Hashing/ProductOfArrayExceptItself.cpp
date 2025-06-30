// https://leetcode.com/problems/product-of-array-except-self/
#include <vector>
using namespace std;
// time complexity = O(n)
// space complexity = O(n)
class Solution
{
public:
    // prefix and suffix product
    // productExceptSelf = prefixProduct * suffixProduct
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        if (n <= 0)
        {
            return ans;
        }

        int prefixProduct = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = prefixProduct;
            prefixProduct = prefixProduct * nums[i];
        }

        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * suffixProduct;
            suffixProduct = suffixProduct * nums[i];
        }

        return ans;
    }
};