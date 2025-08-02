// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
#include "ListNode.h"
// O(2n) = count 0 and 1s

// O(n) = segregate into three lists and join
class Solution
{
public:
    ListNode *segregate(ListNode *head)
    {
        ListNode *zeroHead = new ListNode(0);
        ListNode *zeroTail = zeroHead;

        ListNode *oneHead = new ListNode(0);
        ListNode *oneTail = oneHead;

        ListNode *twoHead = new ListNode(0);
        ListNode *twoTail = twoHead;

        while (head)
        {
            if (head->data == 0)
            {
                zeroTail->next = head;
                zeroTail = zeroTail->next;
            }
            else if (head->data == 1)
            {
                oneTail->next = head;
                oneTail = oneTail->next;
            }
            else
            {
                twoTail->next = head;
                twoTail = twoTail->next;
            }
            head = head->next;
        }

        // Important: terminate the last tail
        twoTail->next = nullptr;

        // Connect the three lists
        // orders should be maintained
        oneTail->next = twoHead->next;
        zeroTail->next = oneHead->next;

        // Return the final head
        return zeroHead->next;
    }
};

// O(2n)
class Solution
{
public:
    ListNode *segregate(ListNode *head)
    {
        int count0s = 0;
        int count1s = 0;

        ListNode *curr = head;
        while (curr)
        {
            int val = curr->data;
            if (val == 0)
                count0s++;
            else if (val == 1)
                count1s++;
            curr = curr->next;
        }

        curr = head;
        while (curr)
        {
            if (count0s)
            {
                curr->data = 0;
                count0s--;
            }
            else if (count1s)
            {
                curr->data = 1;
                count1s--;
            }
            else
            {
                curr->data = 2;
            }
            curr = curr->next;
        }

        return head;
    }
};