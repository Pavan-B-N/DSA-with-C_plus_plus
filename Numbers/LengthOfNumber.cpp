// find length of the given number
#include <iostream>
#include <cmath>
using namespace std;

// using divison
int len(int n)
{
    int l = 0;
    while (n > 0)
    {
        n = n / 10;
        l++;
    }
    return l;
}
// using logarithm
/*
log10 of any number n is euqal to (n-1) decimals
*/
int lengthOfNumber(int n)
{
    return (floor(log10(n))) + 1;
}
int main()
{
    int num = 12345;
    int res = len(num);
    cout << res << endl;

    res = lengthOfNumber(num);
    cout << res << endl;

    return 0;
}