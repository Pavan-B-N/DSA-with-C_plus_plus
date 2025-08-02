// https://leetcode.com/problems/reverse-words-in-a-string/
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {

        string ans = "";

        reverse(s.begin(), s.end());

        stringstream ss(s);
        string word;

        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            ans += word + " ";
        }
        int n = ans.size();
        ans.resize(n - 1);

        return ans;
    }
};

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++)
        {
            string word = "";
            while (i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            if (word.length() > 0)
            {
                reverse(word.begin(), word.end());
                ans += ' ' + word;
            }
        }

        return ans.substr(1);
    }
};