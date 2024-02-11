#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

Node* inPlaceReversal(Node *head){
    if(head->next==nullptr){
        return head;
    }
    Node *previous=nullptr;
    Node *current=head;
    Node *next=head->next;
    while(current!=nullptr){
        current->next=previous;
        previous=current;
        current=next;
        if(next!=nullptr){
            next=next->next;
        }
    }
    return previous;
}

int main(){
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.head=inPlaceReversal(list.head);

    list.display();
    return 0;
}