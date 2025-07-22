// https://www.naukri.com/code360/problems/increasing-letter-triangle_6581897
/*
Sample Input 1:
3
Sample Output 1:
A
A B
A B C

Sample Input 2 :
4
Sample Output 2 :
A
A B
A B C
A B C D
*/
#include <iostream>
using namespace std;

void nLetterTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            char ch = 'A' + j;
            cout << ch << " ";
        }
        cout << endl;
    }
}