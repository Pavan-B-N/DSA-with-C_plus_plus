/*
An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively. 

Input: [-1, 2, -3, 4, 5, 6, -7, 8, 9]
Output:[9, -7, 8, -3, 5, -1, 2, 4, 6]

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();

    // Initializing an answer array of size n
    vector<int> ans(n, 0);

    // Initializing two pointers to track even and
    // odd indices for positive and negative integers respectively
    int posIndex = 0, negIndex = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={-1, 2, -3, 4, 5, 6, -7, 8, 9};
    arr=rearrangeArray(arr);

    for(auto &ele:arr){
        cout<<ele<<" ";
    }
}