//use slow and fast pointer method to remove the cycle
#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

// after cycle detected
Node* startOfLoop(Node *head,Node *fast,Node *slow){
    fast=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;// or fast
}