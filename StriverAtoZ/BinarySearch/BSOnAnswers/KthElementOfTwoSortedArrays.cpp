// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
#include <vector>
using namespace std;

// time complexity = O( log (min(n1,n2)))
class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n1 = a.size(), n2 = b.size();

        // Ensure a is the smaller array
        if (n1 > n2)
            return kthElement(b, a, k);

        if (k > n1 + n2)
            return -1;

        int start = max(0, k - n2), end = min(k, n1);

        while (start <= end)
        {
            int mid1 = (start + end) / 2;
            int mid2 = k - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : a[mid1];

            int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
            int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                end = mid1 - 1;
            }
            else
            {
                start = mid1 + 1;
            }
        }

        return -1;
    }
};

// time complexity = O(n1+n2)
class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int kthElement)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < a.size() && j < b.size())
        {
            int val = 0;
            if (a[i] < b[j])
            {
                val = a[i++];
            }
            else
            {
                val = b[j++];
            }
            k++;
            if (k == kthElement)
            {
                return val;
            }
        }

        while (i < a.size())
        {
            int val = a[i++];
            k++;
            if (k == kthElement)
            {
                return val;
            }
        }
        while (j < b.size())
        {
            int val = b[j++];
            k++;
            if (k == kthElement)
            {
                return val;
            }
        }
        return -1;
    }
};