// https://www.naukri.com/code360/problems/star-triangle_6573671
/*
  *
 ***
*****
*/
#include <iostream>
using namespace std;

void nStarTriangle(int n)
{
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
}