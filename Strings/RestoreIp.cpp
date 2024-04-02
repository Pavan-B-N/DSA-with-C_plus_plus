/*

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(string s)
{
    // If the length of segment is more than 1 and the segment starts with 0, it's not valid
    if (s.length() > 1 && s[0] == '0')
        return false;
    // Convert the segment into an integer
    int num = stoi(s);
    // The segment should lie between 0 and 255
    return num >= 0 && num <= 255;
}

// Time Complexity: O(n^3),
vector<string> genIp(string s)
{
    vector<string> ans;
    // The string length should be between 4 and 12 characters to form a valid IP address
    if (s.length() < 4 || s.length() > 12)
        return ans;
    // Generate all possible combinations of the IP address by placing '.' after 1st, 2nd, and 3rd characters
    for (int i = 1; i < s.length() - 2; i++)
    {
        for (int j = i + 1; j < s.length() - 1; j++)
        {
            for (int k = j + 1; k < s.length(); k++)
            {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i, j - i);
                string s3 = s.substr(j, k - j);
                string s4 = s.substr(k);
                // If all segments are valid, combine them to form an IP address
                if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                {
                    string ip = s1 + "." + s2 + "." + s3 + "." + s4;
                    ans.push_back(ip);
                }
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "25525511135";
    vector<string> ans = genIp(s);
    // Print all possible valid IP addresses
    for (auto ip : ans)
        cout << ip << "\n";
    return 0;
}
