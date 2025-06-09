// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#include <vector>
#include <algorithm>
#include <numeric> // accumulate to find sum of elements
using namespace std;

class Solution
{
public:
    int findPages(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        if (k > n)
        {
            return -1;
        }

        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isPossibleToAllocateExactlyToKStudents(arr, mid, k))
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return start; // or return start;
    }

    bool isPossibleToAllocateExactlyToKStudents(vector<int> &arr, int maxPages, int students)
    {
        int n = arr.size();
        int prevSum = 0;
        int allotedStudents = 1; // start with first student

        for (int i = 0; i < n; i++)
        {
            prevSum += arr[i];

            if (prevSum > maxPages)
            {
                allotedStudents++;
                prevSum = arr[i];
                if (allotedStudents > students)
                    return false;
            }
        }

        return allotedStudents <= students; // allocated within given students
    }
};