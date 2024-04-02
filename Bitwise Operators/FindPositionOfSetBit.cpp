/*
Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1
Input:
N = 2
Output:
2
Explanation:
2 is represented as "10" in Binary.

Input:
N = 5
Output:
-1
Explanation:
5 is represented as "101" in Binary.

*/
#include <iostream>
using namespace std;

int isPowerOfTwo(unsigned n) 
{ 
    return n && (!(n & (n - 1))); 
} 
  
int findPosition(unsigned n) 
{ 
    if (!isPowerOfTwo(n)) 
        return -1; 
  
    unsigned i = 1, pos = 1; 
  
    while (!(i & n)) { 
        i = i << 1; 
        ++pos; 
    } 
  
    return pos; 
}

int main(int argc, char const *argv[])
{
    int n = 12; 
    int pos = findPosition(n); 
    cout<<pos<<endl;
    return 0;
}
