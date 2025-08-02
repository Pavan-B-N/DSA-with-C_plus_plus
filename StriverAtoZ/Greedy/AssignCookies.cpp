// https://leetcode.com/problems/assign-cookies/
/*
You are given:

A list of children, where each child has a greed factor (how big a cookie they need to be happy).
A list of cookies, where each cookie has a size.

g[]: Greed factor of each child.
s[]: Sizes of available cookies.

Give cookies to as many children as possible such that:

Each child gets at most one cookie.

A child is only satisfied if the cookie size >= their greed.
*/
#include <vector>
#include <algorithm>
using namespace std;

// O( nlogn + mlogm)
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // i for greedFactor g
        // j for size of the Cookie s
        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                i++; // child satisfied
            }
            j++; // move to next cookie
        }
        return i;
    }
};