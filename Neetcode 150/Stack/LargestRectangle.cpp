// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        stack<int> s; // stores indices
        // monotonic stack,
        // previous smaller element
        int n = heights.size();
        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && (i == n || heights[s.top()] > heights[i]))
            {
                int h = heights[s.top()];
                s.pop();
                int nse = i;
                int pse = s.empty() ? -1 : s.top();
                int w = nse - pse - 1;
                int area = h * w;
                maxArea = max(maxArea, area);
            }
            s.push(i);
        }
        return maxArea;
    }
};