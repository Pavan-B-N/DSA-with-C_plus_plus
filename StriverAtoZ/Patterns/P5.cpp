// https://www.naukri.com/code360/problems/seeding_6581892
/*
 * * *
 * *
 *
 */
#include <iostream>
using namespace std;

void seeding(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}