// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
#include "ListNode.h"

class Solution
{
public:
    ListNode *flatten(ListNode *root)
    {
        if (!root || !root->next)
            return root;

        // Recursively flatten the next list
        root->next = flatten(root->next);

        // Merge current list (root) with the flattened next list
        root = merge(root, root->next);

        return root;
    }

    ListNode *merge(ListNode *a, ListNode *b)
    {
        // Dummy ListNode to help build the merged list
        ListNode dummy(0);
        ListNode *tail = &dummy;

        // Merge two sorted bottom-linked lists
        while (a && b)
        {
            if (a->data < b->data)
            {
                tail->bottom = a;
                a = a->bottom;
            }
            else
            {
                tail->bottom = b;
                b = b->bottom;
            }
            tail = tail->bottom;
        }

        // Attach the remaining list
        tail->bottom = a ? a : b;

        return dummy.bottom;
    }
};