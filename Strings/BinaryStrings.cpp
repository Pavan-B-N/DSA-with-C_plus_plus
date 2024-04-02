/*
Given a binary string str of length N, the task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced

Input: str = “0100110101” 
Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.
Input: str = “0111100010” 
Output: 3 

Input: str = “0000000000” 
Output: -1

*/
#include <iostream>
using namespace std;

// Time complexity: O(N)
int maxBinarySubStr(string str)
{
    int count0 = 0, count1 = 0;
 
    int counter = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        if (count0 == count1) {
            counter++;
        }
    }

    // It is not possible to
    if (count0!=count1) {
        return -1;
    }
 
    return counter;
}

int main(int argc, char const *argv[])
{
    string str="0100110101";//4

    cout<<"counter: "<<maxBinarySubStr(str)<<endl;
    
    return 0;
}

