/*
Input : n = 6
Output : 2
Binary representation of 6 is 110 and has 2 set bits
*/
#include <iostream>
using namespace std;

int countSetBits(unsigned int n)
{
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    int i = 6;
    cout << countSetBits(i);
    return 0;
}