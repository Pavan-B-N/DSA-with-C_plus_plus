// https://www.naukri.com/code360/problems/rotated-triangle_6573688
/*
 *
 **
 ***
 **
 *
 */

#include <iostream>
using namespace std;

void nStarTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void nStarTriangle(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i <= n ? i : 2 * n - i;
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
