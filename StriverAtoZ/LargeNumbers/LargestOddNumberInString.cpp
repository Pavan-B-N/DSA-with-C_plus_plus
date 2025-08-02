// https://leetcode.com/problems/largest-odd-number-in-string/description/
/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
*/
#include <string>
using namespace std;

class Solution
{
public:
    // intution: if the ith digit is not divisible then the num from 0 to i is
    // the odd if the lastdigit is not divisible by 2 then its a entire odd
    // number 52 = 5 is not divisible so largets odd = 5 4206 = all are
    // divisible by 2 so largest odd = "" 35427  = 7 is not divisible by 2 hence
    // entire number is odd
    string largestOddNumber(string num)
    {
        int n = num.size();
        int i = n - 1;
        while (i >= 0)
        {
            int digit = num[i] - '0';
            if (digit % 2 != 0)
                break;
            i--;
        }
        return num.substr(0, i + 1);
    }
};