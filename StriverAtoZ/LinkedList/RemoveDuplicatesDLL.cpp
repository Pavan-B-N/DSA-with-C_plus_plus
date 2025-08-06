// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
/*
Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

Input:
n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is 
retained, rest nodes with value = 1 are deleted.
*/
#include "ListNode.h"

class Solution
{
public:
    ListNode *removeDuplicates(struct ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *curr = head->next;
        while (curr)
        {
            ListNode *prev = curr->prev;
            ListNode *next = curr->next;
            if (curr->data == prev->data)
            {
                // duplicated
                prev->next = next;
                if (next)
                    next->prev = prev;
            }
            curr = next;
        }

        return head;
    }
};