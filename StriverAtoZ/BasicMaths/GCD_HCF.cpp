
// https://www.naukri.com/code360/problems/hcf-and-lcm_840448?leftPanelTabValue=PROBLEM
#include <iostream>
using namespace std;

// O(min(a,b))
int calcGCD(int a, int b)
{
    int gcd = 1;
    int minEle = min(a, b);

    for (int i = 2; i <= minEle; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}