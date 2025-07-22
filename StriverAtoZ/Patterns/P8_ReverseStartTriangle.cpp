// https://www.naukri.com/code360/problems/reverse-star-triangle_6573685
/*
*****
 ***
  *
*/
#include <iostream>
using namespace std;

void nStarTriangle(int n)
{
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