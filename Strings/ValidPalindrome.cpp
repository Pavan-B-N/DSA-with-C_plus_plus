// https://leetcode.com/problems/valid-palindrome/
#include <string>
using namespace std;
bool isPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        while (i < j && !isalnum(s[i]))
        {
            i++;
        }
        while (i < j && !isalnum(s[j]))
        {
            j--;
        }
        if (tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}