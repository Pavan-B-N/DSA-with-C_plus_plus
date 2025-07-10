// https://leetcode.com/problems/counting-bits/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            ans[i] = count1s(i);
        }
        return ans;
    }

    //  O(k), where k = number of set bits
    int count1s(int n)
    {
        int setBits = 0;
        while (n > 0)
        {
            n = n & (n - 1);
            setBits++;
        }
        return setBits;
    }
};