// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
#include "ListNode.h"

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;

        ListNode* slow=head;
        ListNode* fast=head->next;
        // fast->next->next = we need to stop before reaching to middle that is at mid-1
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow->next){
            slow->next=slow->next->next;
        }

        return head;
    }
};