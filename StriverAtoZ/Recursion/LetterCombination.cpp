// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.size() == 0)
        {
            return res;
        }
        string curr;
        vector<string> mapping = {"", "", // 0, 1 (not used)
                                  "abc", "def", "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};

        backtrack(0, digits, mapping, curr, res);
        return res;
    }
    void backtrack(int index, string digits, vector<string> &mapping,
                   string &curr, vector<string> &res)
    {
        if (curr.size() == digits.size())
        {
            res.push_back(curr);
            return;
        }

        int digit = (digits[index] - '0');
        for (char ch : mapping[digit])
        {
            curr.push_back(ch);
            backtrack(index + 1, digits, mapping, curr, res);
            curr.pop_back();
        }
    }
};