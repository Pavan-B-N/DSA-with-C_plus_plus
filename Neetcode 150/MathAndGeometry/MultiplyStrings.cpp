// https://leetcode.com/problems/multiply-strings/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        string res = "0";
        int zeroPadding = 0;

        for (int i = num2.size() - 1; i >= 0; i--)
        {
            int carry = 0;
            string curr;

            int n2 = num2[i] - '0';
            for (int j = num1.size() - 1; j >= 0; j--)
            {
                int n1 = num1[j] - '0';
                int prod = n1 * n2 + carry;
                curr.push_back((prod % 10) + '0');
                carry = prod / 10;
            }

            if (carry)
                curr.push_back(carry + '0');
            reverse(curr.begin(), curr.end());

            // Append trailing zeroes (simulate shifting)
            for (int k = 0; k < zeroPadding; k++)
            {
                curr.push_back('0');
            }

            res = addTwoNumbers(res, curr);
            zeroPadding++;
        }

        return res;
    }

    string addTwoNumbers(string &num1, string &num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string res;

        while (i >= 0 || j >= 0 || carry)
        {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int sum = a + b + carry;
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
