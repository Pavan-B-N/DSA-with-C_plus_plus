// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// tag: [favorite]
#include <vector>
#include <numeric> //accumulate
#include <algorithm>
using namespace std;
/*
Input: nums = [25, 46, 28, 49, 24], m=4

Output: 71

Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
*/
// log2​(sum(arr)−max(arr))≈log2​(sum)
// O(n * log(sum) )
class Solution
{
public:
    int findPages(vector<int> &arr, int k)
    {
        if (k > arr.size())
        {
            return -1;
        }
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            bool isPossible = isPossibleToAllocate(arr, k, mid);
            if (isPossible)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
    bool isPossibleToAllocate(vector<int> &arr, int k, int maxPages)
    {
        int students = 1;
        int allocatedPages = 0;
        for (int pages : arr)
        {
            if (pages + allocatedPages <= maxPages)
            {
                allocatedPages += pages;
            }
            else
            {
                students++;
                allocatedPages = pages;
            }
        }
        return students <= k;
    }
};