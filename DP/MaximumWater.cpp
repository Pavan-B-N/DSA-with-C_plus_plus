// https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150

/*
You are given an integer array height of length n
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

*/
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int> &height)
{
    int maxWater = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j)
    {
        int width = (j - i);
        int altitude = min(height[i], height[j]);
        int waterStorage = width * altitude;
        if (waterStorage > maxWater)
        {
            maxWater = waterStorage;
        }
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return maxWater;
}

int main(){
    vector<int> heights={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(heights);
    return 0;
}