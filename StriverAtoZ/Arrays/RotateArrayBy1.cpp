// https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &arr)
    {
        int n = arr.size();

        // No need to rotate if array has 0 or 1 elements
        if (n <= 1)
            return;

        // Store the last element
        int lastElement = arr[n - 1];

        // Shift all elements to the right
        for (int i = n - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        // Place the last element at the front
        arr[0] = lastElement;
    }
};
