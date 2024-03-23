// Check if given strings are rotations of each other or not
/*
Given a string s1 and a string s2, write a function to check whether s2 is a rotation of s1. 
Input: S1 = ABCD, S2 = CDAB
Output: Strings are rotations of each other
*/
#include <iostream>
#include <algorithm>
using namespace std;

string leftRotate(string str, int k) {
    reverse(str.begin(), str.end());
    reverse(str.begin(), str.begin() + k);
    reverse(str.begin() + k, str.end());
    return str;
}

bool isRotation(string str1, string str2) {
    int n = str1.length();
    if (n != str2.length())
        return false;

    for (int i = 0; i < n; ++i) {
        if (str1 == str2)
            return true;
        str1 = leftRotate(str1, 1); // rotate `str1` by 1 position to the left
    }
    return false;
}

int main() {
    string str1 = "ABCD";
    string str2 = "CDAB";
    cout << "Is Rotation: " << isRotation(str1, str2) << endl;
    return 0;
}
