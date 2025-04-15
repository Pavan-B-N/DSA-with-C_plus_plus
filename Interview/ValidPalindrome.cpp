// https://leetcode.com/problems/valid-palindrome/
/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/
#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        while(i<j && !isalnum(s[i])){
            i++;
        }
        while(i<j && !isalnum(s[j])){
            j--;
        }
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}