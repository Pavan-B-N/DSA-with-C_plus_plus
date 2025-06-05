// https://leetcode.com/problems/next-greater-element-i/
/**
 * You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
 * so this means that we need to find the next greater element of the nums1[i] in the nums2 where nums1[i] is present in nums2[j]
 *
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/

// steps to solve the problem
/**
 * First find the next greater elements in the nums2 and store the result in unordered_map
 * then we can easily find the NGE for subset as well;
 */
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                map[nums2[i]] = -1;
            }
            else
            {
                map[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        vector<int> res;
        for (int ele : nums1)
        {
            int nge = map[ele];
            res.push_back(nge);
        }

        return res;
    }
};