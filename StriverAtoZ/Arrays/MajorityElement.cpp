// https://leetcode.com/problems/majority-element/
/*
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // moores algo
        int freq = 0;
        int ans = 0;
        for (int ele : nums)
        {
            if (freq == 0)
            {
                ans = ele;
            }
            if (ele == ans)
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
        return ans;
    }
};