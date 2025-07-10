// https://leetcode.com/problems/single-number/

#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int ele : nums)
        {
            // bitwise xor operation
            ans = ans ^ ele;
        }
        return ans;
    }
};