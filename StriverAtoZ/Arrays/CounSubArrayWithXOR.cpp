// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
/*
Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
*/
// tag: [favorite]
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        unordered_map<int, int> hashMap; //{XR,count}
        int xr = 0;
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            xr = xr ^ arr[i];

            if (xr == k)
            {
                count++;
            }

            int x = xr ^ k;
            if (hashMap.count(x))
            {
                count += hashMap[x];
            }
            hashMap[xr]++;
        }
        return count;
    }
};