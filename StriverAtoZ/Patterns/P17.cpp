// https://www.naukri.com/code360/problems/ninja-and-the-star-pattern-i_6581920
/*
Sample Input 1:
3
Sample Output 1:
***
* *
***
Sample Input 2 :
5
Sample Output 2 :
*****
*   *
*   *
*   *
*****
Sample Input 3 :
8
Sample Output 3 :
********
*      *
*      *
*      *
*      *
*      *
*      *
********
*/

#include <iostream>
using namespace std;

void getStarPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
