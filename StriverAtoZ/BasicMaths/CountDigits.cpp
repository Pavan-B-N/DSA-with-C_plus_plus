// https://www.geeksforgeeks.org/problems/count-digits-1606889545/1
#include <iostream>
using namespace std;

// time complexity = O(log10(N))

class Solution
{
public:
    int countDigits(int n)
    {
        int count = 0;
        while (n != 0)
        {
            n = n / 10;
            count++;
        }
        return count;
    }
};

class Solution
{
public:
    int countDigits(int n)
    {
        return floor(log10(n)) + 1;
    }
};