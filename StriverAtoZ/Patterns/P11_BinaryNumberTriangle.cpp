// https://www.naukri.com/code360/problems/binary-number-triangle_6581890
/*

Sample Input 1:
3
Sample Output 1:
1
0 1
1 0 1

Sample Input 2 :
4
Sample Output 2 :
1
0 1
1 0 1
0 1 0 1

Sample Input 3 :
6
Sample Output 3 :
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
0 1 0 1 0 1

*/
#include <iostream>
using namespace std;

void nBinaryTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        int start = i % 2 == 0 ? 1 : 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = !start;
        }
        cout << endl;
    }
}