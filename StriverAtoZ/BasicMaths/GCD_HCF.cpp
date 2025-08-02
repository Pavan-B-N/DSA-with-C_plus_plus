
// https://www.naukri.com/code360/problems/hcf-and-lcm_840448?leftPanelTabValue=PROBLEM
#include <iostream>
using namespace std;
// brute force = // O(min(a,b))
//  optimal = O(log min(n,m))

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

// O(log min(n,m))
int calcGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}