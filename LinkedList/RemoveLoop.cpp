//use slow and fast pointer method to remove the cycle
#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

// only when we have complete circle
void removeLoop(Node *head){
    //find tailNode
    Node *tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=nullptr;
}

Node* startOfLoop(Node *head,Node *slow){
    while(head!=slow){
        head=head->next;
        slow=slow->next;
    }
    return slow;
}

// half cirular loop
void removeLLLoop(Node *head){
    Node *slow=head;
    Node *fast=head;

    //detect the loop point
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            //cycle detected
            // find starting point of the syble
            Node *start=startOfLoop(head,slow);
            do{
                slow=slow->next;
            }while(slow->next!=start);
            slow->next=nullptr;
            break;
        }
    }
}

