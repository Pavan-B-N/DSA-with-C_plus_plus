// https://leetcode.com/problems/valid-parenthesis-string/
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
// 3 ways to solve
// DP + memo = O(n^2) both
// stack = O(n), O(n) extra space for stacks
// greedy = O(n) with constant time complexity

// Time: O(n)
// Space: O(n) — for two stacks
class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> openStack, starStack;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                openStack.push(i);
            }
            else if (ch == '*')
            {
                starStack.push(i);
            }
            else if (ch == ')')
            {
                if (!openStack.empty())
                {
                    openStack.pop(); // match with '('
                }
                else if (!starStack.empty())
                {
                    starStack.pop(); // match with '*'
                }
                else
                {
                    return false; // no match
                }
            }
        }

        // Match remaining '(' with '*' to the right
        while (!openStack.empty() && !starStack.empty())
        {
            int openIndex = openStack.top();
            int starIndex = starStack.top();
            if (openIndex < starIndex)
            {
                openStack.pop();
                starStack.pop();
            }
            else
            {
                return false; // '*' appears before '(', can't balance )(
            }
        }

        return openStack.empty(); // valid only if no unmatched '(' left
    }
};

// carry range
class Solution
{
public:
    bool checkValidString(const string &s)
    {
        int low = 0, high = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                low++;
                high++;
            }
            else if (c == ')')
            {
                low = max(0, low - 1);
                high--;
            }
            else if (c == '*')
            {
                // '*' might be ')', '(', or empty
                low = max(0, low - 1);
                high++;
            }

            if (high < 0)
            {
                // too many closing parentheses
                return false;
            }
        }
        // in the end, low == 0 means it's possible to balance all '('
        return low == 0;
    }
};

// Time: O(n^2)
// Space: O(n^2)

// Space Complexity: O(n²)
// Recursion depth: O(n) (maximum call stack size)
// Memoization map: up to O(n²) entries in dp[index][count]

// For each index 0...n, the count can range up to n (only non-negative counts are considered due to if (count < 0) return false;).
// So total states = O(n × n) = O(n²).
class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.size();
        // Use map to handle negative counts as well
        unordered_map<int, unordered_map<int, bool>> dp;
        return checkValidString(0, s, 0, dp);
    }

    bool checkValidString(int index, const string &s, int count,
                          unordered_map<int, unordered_map<int, bool>> &dp)
    {
        if (count < 0)
            return false; // invalid state
        if (index == s.size())
            return count == 0;
        if (dp[index].count(count))
            return dp[index][count];

        bool result = false;
        if (s[index] == '(')
        {
            result = checkValidString(index + 1, s, count + 1, dp);
        }
        else if (s[index] == ')')
        {
            result = checkValidString(index + 1, s, count - 1, dp);
        }
        else
        {
            // s[index] == '*', try all 3 possibilities
            result = checkValidString(index + 1, s, count + 1, dp) ||
                     checkValidString(index + 1, s, count - 1, dp) ||
                     checkValidString(index + 1, s, count, dp);
        }

        return dp[index][count] = result;
    }
};
