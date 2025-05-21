/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Input: s = "III"
Output: 3

Input: s = "LVIII"
Output: 58

*/
// https://leetcode.com/problems/roman-to-integer/

#include <iostream>
using namespace std;

int valueOfRoman(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInteger(string s)
{
    int result = 0;
    int prevValue = 0;

    for (int i = s.length() - 1; i >= 0; --i)
    {
        int current = valueOfRoman(s[i]);

        if (current < prevValue)
        {
            result -= current;
        }
        else
        {
            result += current;
        }

        prevValue = current;
    }

    return result;
}
int main()
{
    string str;
    str = "LVIII"; // 58

    int res = romanToInteger(str);
    cout << "Value of roman '" << str << "'  is " << res << endl;
    return 0;
}