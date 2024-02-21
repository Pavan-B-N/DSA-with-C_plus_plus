// https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
    int maxWater=0;
    int i=0;
    int j=height.size()-1;
    while(i<j){
        int width=(j-i);
        int altitude=min(height[i],height[j]);
        int waterStorage=width*altitude;
        if(waterStorage>maxWater){
            maxWater=waterStorage;
        }
            if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return maxWater;
}