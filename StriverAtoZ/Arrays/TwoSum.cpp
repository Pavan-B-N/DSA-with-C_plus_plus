// https://leetcode.com/problems/two-sum/description/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashMap; //{ele,index}
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (hashMap.find(diff) != hashMap.end())
            {
                return {hashMap[diff], i};
            }
            hashMap[nums[i]] = i;
        }
        return {-1, -1};
    }
};