// https://leetcode.com/problems/palindrome-number/
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        int reverseNum = 0;
        int num = x;
        while (x != 0)
        {
            int lastDigit = x % 10;
            if (reverseNum > INT_MAX / 10 || reverseNum < INT_MIN / 10)
            {
                return false;
            }
            reverseNum = (reverseNum * 10) + lastDigit;
            x = x / 10;
        }
        return num == reverseNum;
    }
};