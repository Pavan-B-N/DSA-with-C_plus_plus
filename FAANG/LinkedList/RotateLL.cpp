// https://leetcode.com/problems/rotate-list/
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k <= 0 || head == nullptr || head->next == nullptr)
        {
            return head;
        }

        int len = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }

        k = k % len;
        if (k == 0)
            return head; // No rotation needed

        // Reverse the entire list
        head = reverseLL(head);

        // Split the list into two parts after (k-1) nodes
        ListNode *firstPartTail = getNode(head, k - 1);
        ListNode *secondPartHead = firstPartTail->next;
        firstPartTail->next = nullptr;

        // Reverse both parts individually
        ListNode *newHead = reverseLL(head);
        ListNode *newSecond = reverseLL(secondPartHead);

        //  Attach first part to second part
        ListNode* tempTail = newHead;
        while (tempTail->next != nullptr) {
            tempTail = tempTail->next;
        }
        tempTail->next = newSecond;
        // we can use this instead of tempTail but its not considered as safe traversal
        // head->next = newSecond;

        return newHead;
    }

    ListNode *getNode(ListNode *head, int index)
    {
        while (index > 0 && head != nullptr)
        {
            head = head->next;
            index--;
        }
        return head;
    }

    ListNode *reverseLL(ListNode *start)
    {
        ListNode *prev = nullptr;
        ListNode *curr = start;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
