// https://www.geeksforgeeks.org/problems/second-largest3735/1
#include <vector>
using namespace std;

class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {
        int firstLargest = INT_MIN;
        int secondLargest = INT_MIN;
        for (int ele : arr)
        {
            if (ele > firstLargest)
            {
                secondLargest = firstLargest;
                firstLargest = ele;
            }
            else if (ele > secondLargest && ele < firstLargest)
            {
                secondLargest = ele;
            }
        }
        return secondLargest == INT_MIN ? -1 : secondLargest;
    }
};