/*
-  converts a string to a 32-bit signed integer.
- Ignore any leading whitespace (" ").
-  Determine the negative sign
- Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
- Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
*/
#include <string>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, n = s.length();
        long long res = 0;
        int sign = 1;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // Step 2: Check for sign
        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Parse digits
        while (i < n && isdigit(s[i]))
        {
            int num = s[i] - '0';

            // Step 4: Check for overflow
            if (res > (INT_MAX - num) / 10)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + num;
            i++;
        }

        return static_cast<int>(res * sign);
    }
};
