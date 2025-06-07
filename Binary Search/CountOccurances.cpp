// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // binary search
    // (lastIndex - firstIndex) + 1
    int countFreq(vector<int> &arr, int target)
    {
        int n = arr.size();
        int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        if (lb == n || arr[lb] != target)
        {
            return 0;
        }
        int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

        int firstIndex = lb;
        int lastIndex = ub - 1;
        return (lastIndex - firstIndex) + 1;// or ub - lb;
    }
};

// when interviewer asks for a implementation of lower_bound and upperbound
class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        int lb = getBound(arr, target, true);
        if (lb == arr.size() || arr[lb] != target)
            return 0;
        int ub = getBound(arr, target, false);
        return ub - lb;
    }

    int getBound(vector<int> &arr, int target, bool isLower)
    {
        int start = 0, end = arr.size() - 1, bound = arr.size();
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] > target || (isLower && arr[mid] == target))
            {
                bound = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return bound;
    }
};
