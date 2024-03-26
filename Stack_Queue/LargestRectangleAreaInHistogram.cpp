/*
https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-stack/

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

int largestRectangleAreaStack(vector<int> &heights)
{
    stack<int> s;
    int max_area = 0;
    int n = heights.size();

    for (int i = 0; i <= n; ++i)
    {
        while (!s.empty() && (i == n || heights[i] < heights[s.top()]))
        {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            max_area = max(max_area, h * w);
        }
        s.push(i);
    }

    return max_area;
}

int main()
{
    vector<int> heights = {6,2,5,4,5,1,6};
    cout << "Largest rectangular area: " << largestRectangleAreaNaive(heights) << endl;
    cout << "Largest rectangular area: " << largestRectangleAreaStack(heights) << endl;
    return 0;
}
