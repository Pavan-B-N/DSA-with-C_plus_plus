// https://www.naukri.com/code360/problems/increasing-number-triangle_6581893
/*
Sample Input 1:
3
Sample Output 1:
1
2 3
4 5 6

Sample Input 2 :
4
Sample Output 2 :
1
2 3
4 5 6
7 8 9 10
*/
#include <iostream>
using namespace std;

void nNumberTriangle(int n)
{
    int end = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (++end) << " ";
        }
        cout << endl;
    }
}