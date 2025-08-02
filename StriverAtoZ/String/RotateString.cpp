// https://leetcode.com/problems/rotate-string/
/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity. O(n²)
class Solution
{
public:
    //  generating a new rotated string in each iteration using substr, which takes O(n)
    // time complexity. O(n²)
    bool rotateString(string s, string goal)
    {
        if (s == goal)
            return true;
        for (int i = 0; i < s.size(); i++)
        {
            string newStr = s.substr(i + 1) + s.substr(0, i + 1);
            if (newStr == goal)
                return true;
        }
        return false;
    }
};

//  Time: O(n)
// Space: O(n), due to concatenated string s + s.
class Solution
{
public:
    // Find method
    // If the substring is found, it returns the index (position) of the first occurrence.

    // If the substring is not found, it returns string::npos (a constant representing "not found").
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        string doubledStr = s + s;
        return doubledStr.find(goal) != string::npos;
    }
};