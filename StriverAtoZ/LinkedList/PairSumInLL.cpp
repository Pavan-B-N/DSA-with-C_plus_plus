// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
/*
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
*/
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(ListNode *head, int target)
    {
        if (!head || !head->next)
        {
            return {};
        }
        ListNode *first = head;
        ListNode *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }

        vector<pair<int, int>> res;
        while (first != last && first->prev != last)
        {
            int sum = first->data + last->data;
            if (sum == target)
            {
                res.push_back({first->data, last->data});
                first = first->next;
                last = last->prev;
            }
            else if (sum > target)
            {
                last = last->prev;
            }
            else
            {
                first = first->next;
            }
        }
        return res;
    }
};