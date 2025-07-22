// https://leetcode.com/problems/sort-colors/description/
/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};