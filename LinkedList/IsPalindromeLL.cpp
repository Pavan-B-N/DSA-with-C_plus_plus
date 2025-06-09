// https://leetcode.com/problems/palindrome-linked-list/description/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *mid = findMid(head);
        ListNode *head2 = reverseLL(mid);
        mid->next = nullptr;

        while (head != nullptr && head2 != nullptr)
        {
            if (head->val != head2->val)
            {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Mid: " << slow->val << endl;
        return slow;
    }

    ListNode *reverseLL(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;

        while (curr != nullptr)
        {
            curr->next = pre;
            pre = curr;
            curr = next;
            if (next)
            {
                next = next->next;
            }
        }
        return pre;
    }
};