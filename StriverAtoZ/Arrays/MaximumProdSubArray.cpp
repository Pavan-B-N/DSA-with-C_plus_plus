// https://leetcode.com/problems/maximum-product-subarray/

#include <vector>
using namespace std;
// tag: [favorite]
// improved version, finding prefixProd and suffixProd in single iteration
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=INT_MIN;
        int prefixProd=1;
        int suffixProd=1;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(prefixProd==0) prefixProd=1;
            if(suffixProd==0) suffixProd=1;
            
            prefixProd*=nums[i];
            suffixProd*=nums[n-i-1];
            int currMax=max(prefixProd,suffixProd);
            maxProd=max(maxProd,currMax);
        }
        return maxProd;
    }
};

// complete intution
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxProd = INT_MIN;
        int prefixProd = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixProd *= nums[i];
            maxProd = max(maxProd, prefixProd);
            if (prefixProd == 0)
            {
                prefixProd = 1;
            }
        }
        int suffixProd = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            suffixProd *= nums[i];
            maxProd = max(maxProd, suffixProd);
            if (suffixProd == 0)
            {
                suffixProd = 1;
            }
        }
        return maxProd;
    }
};