/*
given a number a and b
find the number that lies between a and b which can be represented as 2 exponent
*/

#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 14;
    a=10,b=100;
    int max = 0;
    int res = 0;
    for (int i = a; i <= b; i++)
    {
        int n = i;
        int c = 0;
        while (n % 2 != 1 && n > 0)
        {
            n /= 2;
            c++;
        }
        if (c > max)
        {
            max = c;
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}