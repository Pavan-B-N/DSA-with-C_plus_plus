// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms = 1;
        int maxPlatforms = 1;
        int i = 1, j = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platforms++; // Need new platform
                i++;
            }
            else
            {
                platforms--; // One train departs
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};
