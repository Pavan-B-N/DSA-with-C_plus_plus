// https://www.geeksforgeeks.org/problems/find-length-of-loop/1
#include "ListNode.h"

class Solution
{
public:
    int lengthOfLoop(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            // loop detect
            if (slow == fast)
            {
                int count = 0;
                do
                {
                    fast = fast->next;
                    count++;
                } while (slow != fast);

                return count;
            }
        }

        return 0;
    }
};