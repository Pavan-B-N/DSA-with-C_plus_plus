// https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
// https://www.naukri.com/code360/problems/factorial_975273?leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;

class Solution
{
public:
    //   Time Complexity	O(n log n)
    // Space Complexity	O(n log n)
    vector<int> factorial(int n)
    {
        vector<int> res;
        res.push_back(1);

        for (int i = 2; i <= n; i++)
        {
            int carry = 0;
            for (int j = 0; j < res.size(); j++)
            {
                int prod = res[j] * i + carry;
                res[j] = prod % 10;
                carry = prod / 10;
            }

            // Push remaining carry digits
            while (carry)
            {
                res.push_back(carry % 10);
                carry /= 10;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
