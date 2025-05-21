#include <iostream>
#include <algorithm>
using namespace std;

string convertToBase(int n, int base)
{
    string res = "";
    while (n > 0)
    {
        int remainder = n % base;
        res += (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

// https://leetcode.com/problems/convert-to-base-2/
string baseNeg2(int n)
{
    int base = -2;
    return convertToBase(n, base);
}

string convertToBase(int n, int base)
{
    if (n == 0)
        return "0";
    string res = "";
    while (n != 0)
    {
        int remainder = n % base;

        n /= base;

        if (remainder < 0)
        {
            remainder += 2; //-1 = 1
            n += 1;         // -1 = 0;
        }

        res +=
            (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n = 17;
    int b = 8;
    cout << convertToBase(n, b);
    return 0;
}
