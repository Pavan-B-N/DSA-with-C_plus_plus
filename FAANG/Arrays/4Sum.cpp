// https://leetcode.com/problems/4sum/description/
#include <vector>
#include <algorithm>
using namespace std;

// o(nlogn + n^3) = o(n^3)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    if (nums.size() < 4)
    {
        return res;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; i++)
    { // o(n)
        // skip duplicate
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size() - 2; j++)
        { // o(n)
            // skip duplicate
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int right = nums.size() - 1;

            while (left < right)
            { // o(n)
                // total sum could overflow the signed integer so always use long long
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // skip duplicate
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return res;
}