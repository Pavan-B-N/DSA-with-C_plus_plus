/**
 * Definition for singly-linked list.
https://leetcode.com/problems/reverse-linked-list-ii/
 */
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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(left==right){
                return head;
            }
            ListNode* start=getNode(head,left);
            ListNode* end=getNode(head,right);
    
            if(start==head && end->next==nullptr){
                inPlaceReversalSubList(head,start,end);
                return end;
            }else if(start==head && end->next!=nullptr){
                ListNode *after=getNode(head,right+1);
                inPlaceReversalSubList(head,start,end);
                start->next=after;
                return end;
            }else if(end->next==nullptr){
                ListNode *before=getNode(head,left-1);
                inPlaceReversalSubList(head,start,end);
                before->next=end;
            }else{
                ListNode *after=getNode(head,right+1);
                ListNode *before=getNode(head,left-1);
                inPlaceReversalSubList(head,start,end);
                start->next=after;
                before->next=end;
            }
    
            return head;
        }
    
        ListNode* getNode(ListNode *head,int position){
            while(head!=nullptr && position>1){
                head=head->next;
                position--;
            }
            return head;
        }
        void inPlaceReversalSubList(ListNode* head, ListNode *start, ListNode *end){
            // reverse sublist
            ListNode *prev=nullptr;
            ListNode *curr=start;
            ListNode *next=start->next;
    
            while(prev!=end){
                curr->next=prev;
                prev=curr;
                curr=next;
                if(next){
                    next=next->next;
                }
            }
        }
    
    
    };