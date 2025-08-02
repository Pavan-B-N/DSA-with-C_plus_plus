#include "ListNode.h"

class Solution
{
public:
    bool searchKey(int n, ListNode *head, int key)
    {
        while (head)
        {
            if (head->data == key)
                return true;
            head = head->next;
        }
        return false;
    }
};
