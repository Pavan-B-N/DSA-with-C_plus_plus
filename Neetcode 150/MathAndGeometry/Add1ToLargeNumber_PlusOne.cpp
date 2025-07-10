// https://leetcode.com/problems/plus-one/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res;
        int n = digits.size();
        int carry = 1; // adding 1 to last digit
        for (int i = n - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry)
        {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};