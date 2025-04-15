
// https://leetcode.com/problems/single-number/
#include <vector>
#include <algorithm>
using namespace std;

// o(n)
int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int ele:nums){
         // bitwise xor operation
         ans=ans^ele;
    }
    return ans;
 }

// n*log(n)
int singleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    // log(n)
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        bool checkLeft = (mid > 0) && nums[mid] == nums[mid - 1];
        bool checkRight = (mid + 1 < n) && nums[mid] == nums[mid + 1];

        bool even = mid % 2 == 0;
        bool odd = mid % 2 == 1;

        if (!checkLeft && !checkRight)
        {
            return nums[mid];
        }
        else if ((even && checkRight) || (odd && checkLeft))
        {
            // my single element is on right side
            start = mid + 1;
        }
        else
        {
            // my single element is on left side
            end = mid - 1;
        }
    }
    return -1;
}
