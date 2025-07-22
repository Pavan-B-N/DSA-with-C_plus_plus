// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
/*
Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
*/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> res;
        int i = 0, j = 0;

        while (i < arr1.size() && j < arr2.size())
        {
            int value;
            if (arr1[i] < arr2[j])
            {
                value = arr1[i++];
            }
            else if (arr2[j] < arr1[i])
            {
                value = arr2[j++];
            }
            else
            {
                value = arr1[i];
                i++;
                j++;
            }

            if (res.empty() || res.back() != value)
                res.push_back(value);
        }

        while (i < arr1.size())
        {
            if (res.empty() || res.back() != arr1[i])
                res.push_back(arr1[i]);
            i++;
        }

        while (j < arr2.size())
        {
            if (res.empty() || res.back() != arr2[j])
                res.push_back(arr2[j]);
            j++;
        }

        return res;
    }
};
