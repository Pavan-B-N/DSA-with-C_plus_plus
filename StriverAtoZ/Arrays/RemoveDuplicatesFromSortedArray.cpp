// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <vector>
using namespace std;

class Solution
{
public:
    // Change the array nums such that the first k elements of nums contain the
    // unique elements in the order they were present in nums initially
    //  The remaining elements of nums are not important as well as the size of
    //  nums.
    // Return k.
    int removeDuplicates(vector<int> &arr)
    {
        int k = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[k] != arr[i])
            {
                arr[++k] = arr[i];
            }
        }
        return k + 1; // because k pointing to the position in the array so size
                      // to k+1
    }
};