// https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto op : tokens)
        {
            if (op != "+" && op != "-" && op != "*" && op != "/")
            {
                s.push(stoi(op));
            }
            else
            {
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();

                int res = 0;
                switch (op[0])
                {
                case '+':
                    res = x + y;
                    break;
                case '-':
                    res = x - y;
                    break;
                case '*':
                    res = x * y;
                    break;
                case '/':
                    res = x / y;
                    break;
                }

                s.push(res);
            }
        }

        return s.top();
    }
};