// https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?leftPanelTabValue=PROBLEM
/*
Delete all occurrences of a given key in a doubly linked list
Input: Linked List: 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 and ‘k’ = 10
Output: Modified Linked List: 4 <-> 3 <-> 5 <-> 20
*/
#include "ListNode.h"

ListNode *deleteAllOccurrences(ListNode *head, int k)
{
    if (!head)
        return nullptr;

    ListNode *curr = head;

    while (curr)
    {
        if (curr->data == k)
        {
            ListNode *prev = curr->prev;
            ListNode *next = curr->next;

            // Reconnect prev and next
            if (prev)
                prev->next = next;
            else
                head = next; // replace head

            if (next)
                next->prev = prev;
        }
        curr = curr->next;
    }

    return head;
}
