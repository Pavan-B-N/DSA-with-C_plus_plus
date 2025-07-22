// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
/*
Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and the missing number is 1.
*/
#include <vector>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        for (int i = 0; i < arr.size(); i++)
        {
            // skip duplicates,  arr[i]!=arr[arr[i]-1]
            while (i != arr[i] - 1 && arr[i] != arr[arr[i] - 1])
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (i != arr[i] - 1)
            {
                return {arr[i], i + 1};
            }
        }

        return {-1, -1};
    }
};