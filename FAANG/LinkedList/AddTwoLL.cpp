// https://leetcode.com/problems/add-two-numbers/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        int carry = 0;
        ListNode *res = new ListNode();
        ListNode *head = res;

        while (l1 != nullptr || l2 != nullptr)
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            sum = x + y + carry;
            carry = sum / 10;

            ListNode *temp = new ListNode(sum % 10);
            res->next = temp;
            res = temp;

            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }
        if (carry > 0)
        {
            ListNode *temp = new ListNode(carry);
            res->next = temp;
            res = temp;
        }

        return head->next;
    }
};