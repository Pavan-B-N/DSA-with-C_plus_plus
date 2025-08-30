/*
https://leetcode.com/problems/largest-rectangle-in-histogram/

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: In this example the largest area would be 12 of height 4 and width 3. We can achieve this
area by choosing 3rd, 4th and 5th bars.

*/
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// O(2N)
// monotonic stack
// intution:- we can form the rectangle only until a smallest histogram which we can find to the left and right
// so possible width of rectangle is = nextSmaller(i) -  prevSmaller(i) - 1
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        stack<int> s; // stores indices
        // monotonic stack,
        // previous smaller element + next smaller element
         // previous smaller element focus
        int n = heights.size();
        for (int i = 0; i <= n; i++)
        {
            // if value < s.top means that for the s.top value is the nse
            while (!s.empty() && (i == n || heights[s.top()] > heights[i]))
            {
                // calculate the area for the previous guy, because now we got the nse for this guy
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
/*
| Resource               | Complexity |
| ---------------------- | ---------- |
| **Time (exact)**       | O(5n)      |
| **Time (asymptotic)**  | O(n)       |
| **Space (exact)**      | O(3n)      |
| **Space (asymptotic)** | O(n)       |
*/
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        // Get previous and next smaller element indices
        vector<int> prev = findPreviousSmaller(heights); // O(2N)
        vector<int> next = findNextSmaller(heights);     // O(2N)

        int maxArea = 0;

        // Compute area for each bar as height[i] * width[i]
        // O(N)
        for (int i = 0; i < n; i++)
        {
            int width = next[i] - prev[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

private:
    // O(2N)
    vector<int> findPreviousSmaller(const vector<int> &heights)
    {
        int n = heights.size();
        vector<int> prev(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            prev[i] = s.empty() ? -1 : s.top(); // If no smaller, mark -1
            s.push(i);
        }

        return prev;
    }
    // O(2N)
    vector<int> findNextSmaller(const vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            next[i] = s.empty() ? n : s.top(); // If no smaller, mark n
            s.push(i);
        }

        return next;
    }
};

// naive approach
int largestRectangleAreaNaive(vector<int> &heights)
{
    int max_area = 0;
    int n = heights.size();
    for (int i = 0; i < n; ++i)
    {
        int min_height = INT_MAX;
        for (int j = i; j < n; ++j)
        {
            min_height = min(min_height, heights[j]);
            max_area = max(max_area, min_height * (j - i + 1));
        }
    }
    return max_area;
}
