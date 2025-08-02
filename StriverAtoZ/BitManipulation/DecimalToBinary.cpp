// https://www.geeksforgeeks.org/problems/decimal-to-binary-1610434291/1
/*
Given a decimal number n, compute its binary equivalent.

Example 1:

Input: n = 7
Output: 111
Input: n = 33
Output: 100001
*/
#include <iostream>
#include <string>
using namespace std;

// Time complexity: O(logn)
// Space complexity: O(logn)
void toBinary(int n)
{
    if (n == 0)
    {
        cout << "0";
        return;
    }

    int base = 2;
    string ans = "";
    while (n != 0)
    {
        int rem = n % base;
        ans += to_string(rem);
        n /= base;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}