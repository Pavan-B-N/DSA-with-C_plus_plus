// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
#include <vector>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr)
    {
        int maxEle = 0;
        for (int ele : arr)
        {
            maxEle = max(maxEle, ele);
        }
        return maxEle;
    }
};
