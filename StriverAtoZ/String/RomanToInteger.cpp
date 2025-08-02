// https://leetcode.com/problems/roman-to-integer/description/
#include <string>
using namespace std;

class Solution
{
public:
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
    int romanToInt(string s)
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
};