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
        vector<int> res;// storing result in reverse order
        res.push_back(1);

        // n=10
        // n!=1*2*3*4*5*6*7*8*9*10
        for (int i = 2; i <= n; i++)
        {
            int carry = 0;
            // multiply digit by digit
            for (int j = 0; j < res.size(); j++)
            {
                int prod = res[j] * i + carry;
                res[j] = prod % 10;// last digit
                carry = prod / 10;// rest part
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
