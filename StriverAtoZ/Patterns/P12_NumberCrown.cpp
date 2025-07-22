// https://www.naukri.com/code360/problems/number-crown_6581894
/*
Sample Input 1:
3
Sample Output 1:
1         1
1 2     2 1
1 2 3 3 2 1

Sample Input 2 :
4
Sample Output 2 :
1             1
1 2         2 1
1 2 3     3 2 1
1 2 3 4 4 3 2 1
*/
#include <iostream>
using namespace std;

void numberCrown(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // print number
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        // print space
        for (int j = 1; j <= (2 * n - 2 * i); j++)
        {
            cout << " ";
        }

        // print nmumbers in reverse order
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}