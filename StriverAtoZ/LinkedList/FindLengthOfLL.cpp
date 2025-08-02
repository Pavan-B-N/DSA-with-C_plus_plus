#include "ListNode.h"

class Solution
{
public:
    int getCount(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};