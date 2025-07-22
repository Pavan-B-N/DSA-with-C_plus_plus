//  https://www.naukri.com/code360/problems/alpha-hill_6581921
/*
Sample Input 1:
3
Sample Output 1:
    A
  A B A
A B C B A

Sample Input 2 :
1
Sample Output 2 :
A
*/
#include <iostream>
using namespace std;

void alphaHill(int n)
{
    for (int i = 0; i < n; i++)
    {
        // print space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // print symbol
        char symbol = 'A';
        for (int j = 0; j <= (2 * i + 1) / 2; j++)
        {
            cout << symbol++ << " ";
        }
        --symbol;
        // print symbol in reverse order
        for (int j = (2 * i + 1) / 2 + 1; j < (2 * i + 1); j++)
        {
            cout << --symbol << " ";
        }

        // print space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}