// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
// Add 1 to a Linked List Number

// Input: LinkedList: 4->5->6
// Output: 457
// 9 = 10
// 999 = 1000
#include "ListNode.h"
#include <stack>
using namespace std;

class Solution
{
public:
    ListNode *addOne(ListNode *head)
    {
        int carry = addOneFromLast(head);

        if (carry)
        {
            ListNode *newListNode = new ListNode(1);
            newListNode->next = head;
            head = newListNode;
        }
        return head;
    }
    int addOneFromLast(ListNode *head)
    {
        if (head == nullptr)
            return 1;

        int carry = addOneFromLast(head->next);
        int sum = head->data + carry;
        head->data = sum % 10;

        return sum / 10;
    }
};

class Solution
{
public:
    ListNode *addOne(ListNode *head)
    {
        if (!head)
            return new ListNode(1);

        stack<ListNode *> s;
        ListNode *curr = head;
        while (curr)
        {
            s.push(curr);
            curr = curr->next;
        }

        while (!s.empty())
        {
            ListNode *top = s.top();
            if (top->data == 9)
            {
                top->data = 0;
                s.pop();
            }
            else
            {
                break;
            }
        }

        if (s.empty())
        {
            ListNode *newListNode = new ListNode(1);
            newListNode->next = head;
            return newListNode;
        }

        else
        {
            ListNode *top = s.top();
            top->data = top->data + 1;
        }

        return head;
    }
};