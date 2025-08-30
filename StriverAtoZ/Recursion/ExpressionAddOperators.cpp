// https://leetcode.com/problems/expression-add-operators/
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        string exp;
        vector<string> ans;
        addOperators(0, num, target, exp, ans);
        return ans;
    }

    void addOperators(int index, string num, int target, string exp,
                      vector<string> &ans)
    {
        if (index == num.size())
        {
            if (evaluateInfix(exp) == target)
            {
                ans.push_back(exp);
            }
            return;
        }

        for (int i = 1; index + i <= num.size(); i++)
        {
            string n = num.substr(index, i);
            if (n.length() > 1 && n[0] == '0')
                break;

            if (exp.empty())
            {
                addOperators(index + i, num, target, n, ans);
            }
            else
            {
                addOperators(index + i, num, target, exp + "+" + n, ans);
                addOperators(index + i, num, target, exp + "-" + n, ans);
                addOperators(index + i, num, target, exp + "*" + n, ans);
            }
        }
    }

    int precedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*')
            return 2;
        return 0;
    }

    long long applyOp(long long a, long long b, char op)
    {
        switch (op)
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        }
        return 0;
    }

    long long evaluateInfix(const string &str)
    {
        stack<long long> values;
        stack<char> ops;
        int i = 0;

        while (i < str.length())
        {
            char ch = str[i];

            if (isdigit(ch))
            {
                long long num = 0;
                while (i < str.length() && isdigit(str[i]))
                {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                values.push(num);
                continue;
            }

            while (!ops.empty() && precedence(ops.top()) >= precedence(ch))
            {
                long long b = values.top();
                values.pop();
                long long a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(a, b, op));
            }

            ops.push(ch);
            i++;
        }

        while (!ops.empty())
        {
            long long b = values.top();
            values.pop();
            long long a = values.top();
            values.pop();
            char op = ops.top();
            ops.pop();
            values.push(applyOp(a, b, op));
        }

        return values.top();
    }
};
