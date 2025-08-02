// https://leetcode.com/problems/single-number/description/
#include <vector>
using namespace std;
// each number appears twice except a single number
class Solution
{
public:
    // bitwise xor operation
    int singleNumber(vector<int> &nums)
    {
        int xorVal = 0;
        for (int ele : nums)
        {
            xorVal = xorVal ^ ele;
        }
        return xorVal;
    }
};