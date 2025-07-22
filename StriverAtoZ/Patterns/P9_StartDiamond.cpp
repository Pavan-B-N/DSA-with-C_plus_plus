// https://www.naukri.com/code360/problems/star-diamond_6573686
/*
  *
 ***
*****
*****
 ***
  *
*/
#include <iostream>
using namespace std;

void nStarDiamond(int n)
{
    // Start Triangle
    for (int i = 0; i < n; i++)
    {
        // print space()
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // print starts()
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        // print space()
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    // Reverse Star Triangle
    for (int i = 0; i < n; i++)
    {
        // print space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // print stars
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++)
        {
            cout << "*";
        }
        // print space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}