// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/0
/*
Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

A binary string is that string which contains only 0 and 1.

Example 1:

Input:
N = 3
Output:
000 , 001 , 010 , 100 , 101

*/

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> generateBinaryStrings(int num)
    {
        vector<string> ans;
        string str;
        generate(false, num, str, ans);
        return ans;
    }
    void generate(bool is1Picked, int num, string str, vector<string> &ans)
    {
        if (num == 0)
        {
            ans.push_back(str);
            return;
        }
        // pick zero
        generate(false, num - 1, str + "0", ans);

        if (!is1Picked)
        {
            generate(true, num - 1, str + "1", ans);
        }
    }
};