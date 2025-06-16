// https://leetcode.com/problems/missing-number/
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        cyclicSort(nums, nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                return i + 1;
            }
        }

        return 0;
    }

    void cyclicSort(vector<int> &arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            while (i != arr[i] - 1)
            {
                if (arr[i] == 0)
                {
                    break;
                }
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
    }
};

// based on maths
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int expectedSum = (n * (n + 1)) / 2;
        return expectedSum - sum;
    }
};