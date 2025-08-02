#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(n, 0, 0, "", res);
        return res;
    }

    void helper(int max, int open, int close, string curr,
                vector<string> &res)
    {
        if (curr.length() == 2 * max)
        {
            res.push_back(curr);
            return;
        }

        if (open < max)
        {
            helper(max, open + 1, close, curr + "(", res);
        }
        if (close < open)
        {
            helper(max, open, close + 1, curr + ")", res);
        }
    }
};