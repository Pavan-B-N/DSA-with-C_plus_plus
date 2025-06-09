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

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* curr = head;
            int cnt = 0;
            // check if k nodes exist
            while(cnt < k) {
                if(curr == NULL) {
                    return head;
                }
                curr = curr->next;
                cnt++;
            }
    
            // recursively call for rest of LL
            ListNode* prevNode = reverseKGroup(curr, k);
    
            // reverse current group
            curr = head;
            cnt = 0;
            while(cnt < k) {
                ListNode* next = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = next;
                cnt++;
            }
    
            return prevNode;
        }
    };
    