/*/
celebrity known to everyone but he does not know anyone

Input:
MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} }
Output: id = 2
Explanation: The person with ID 2 does not know anyone but everyone knows him

*/

// solved using graph, recursion, stack

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        stack<int> s; // stores indices or candidates
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {
            int person1 = s.top();
            s.pop();
            int person2 = s.top();
            s.pop();

            if (mat[person1][person2] == 1)
            {
                // person1 knows person2, sp person1 cannot be celebrity
                // so person2 can be a celebrity
                s.push(person2);
            }
            else
            {
                s.push(person1);
            }
        }

        int celebrity = s.top();
        s.pop();

        for (int i = 0; i < n; i++)
        {
            if (celebrity != i && mat[celebrity][i] == 1 || mat[i][celebrity] == 0)
            {
                return -1;
            }
        }

        return celebrity;
    }
};