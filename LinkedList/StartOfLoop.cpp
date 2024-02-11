//use slow and fast pointer method to remove the cycle
#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

Node* startOfLoop(Node *head,Node *slow){
    while(head!=slow){
        head=head->next;
        slow=slow->next;
    }
    return slow;
}