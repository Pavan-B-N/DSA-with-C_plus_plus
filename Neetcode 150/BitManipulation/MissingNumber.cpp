#include <vector>
#include <numeric>
using namespace std;

// using bitwise xor
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xor1 = 0, xor2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            xor1 ^= nums[i]; // XOR of array
            xor2 ^= i;       // XOR of index
        }
        xor2 ^= n;          // include the last number (n)
        return xor1 ^ xor2; // missing = (0^1^...^n) ^ (nums[0]^nums[1]^...)
    }
};

// using math
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