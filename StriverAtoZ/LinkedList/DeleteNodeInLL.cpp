// https://leetcode.com/problems/delete-node-in-a-linked-list/
#include "ListNode.h"

class Solution
{
public:
    // You will not be given access to the first node of head.
    // All the values of the linked list are unique
    // it is guaranteed that the given node node is not the last node in the linked list.

    // Note that by deleting the node, we do not mean removing it from memory. We mean:
    // The value of the given node should not exist in the linked list.
    // The number of nodes in the linked list should decrease by one.
    // All the values before node should be in the same order.
    // All the values after node should be in the same order.
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};