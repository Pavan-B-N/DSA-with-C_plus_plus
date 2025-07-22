// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// tag: [favorite]
#include <vector>
#include <numeric> //accumulate
#include <algorithm>
using namespace std;

// similar to BinarySearch\BSOnAnswers\AllocateMinimumPages.cpp

class Solution
{
public:
    int minTime(vector<int> &arr, int k)
    {
        int n = arr.size();

        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isPossibleToAllotePainters(arr, k, mid))
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

    bool isPossibleToAllotePainters(vector<int> &nums, int k, int maxSum)
    {
        int prevSum = 0;
        int splits = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (prevSum + nums[i] <= maxSum)
            {
                prevSum += nums[i];
            }
            else
            {
                splits++;
                prevSum = nums[i];
            }
        }

        return splits <= k;
    }
};