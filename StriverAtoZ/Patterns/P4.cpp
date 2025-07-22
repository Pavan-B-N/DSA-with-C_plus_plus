// https://www.naukri.com/code360/problems/triangle_6573690
/*
1
2 2 
3 3 3
*/
#include <iostream>
using namespace std;

void triangle(int n) {
	for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}