// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    int maxLength(vector<int> &arr)
    {
        unordered_map<int, int> hashMap; //{prefixSum,index}
        int maxLen = 0;

        int prefixSum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            prefixSum += arr[i];

            if (prefixSum == 0)
            {
                maxLen = i + 1;
            }

            if (hashMap.count(prefixSum))
            {
                int len = i - hashMap[prefixSum];
                maxLen = max(maxLen, len);
            }
            else
            {
                hashMap[prefixSum] = i;
            }
        }

        return maxLen;
    }
};