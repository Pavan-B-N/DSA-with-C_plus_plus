// https://www.naukri.com/code360/problems/symmetric-void_6581919
/*
Sample Input 1:
3
Sample Output 1:
* * * * * *
* *     * *
*         *
*         *
* *     * *
* * * * * *
Sample Input 2 :
1
Sample Output 2 :
* *
* *
*/
#include <iostream>
using namespace std;

void printTop(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Left stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        // Middle space
        for (int j = 0; j < 2 * i; j++)
        {
            cout << "  ";
        }
        // Right stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printBottom(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Left stars
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        // Middle space

        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            cout << "  ";
        }
        // Right stars
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void symmetry(int n)
{
    printTop(n);
    printBottom(n);
}
