// https://leetcode.com/problems/two-sum/

#include <unordered_map>
using namespace std;

// time complexity = O(n)
// space complexity = O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map; // num,index
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (map.find(diff) != map.end())
            {
                return {map[diff], i};
            }
            map.insert({nums[i], i});
        }
        return {-1, -1};
    }
};