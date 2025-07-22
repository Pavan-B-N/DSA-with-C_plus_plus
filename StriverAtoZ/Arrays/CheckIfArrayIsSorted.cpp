// https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSorted(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < arr[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};