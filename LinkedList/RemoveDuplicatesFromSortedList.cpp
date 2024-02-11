#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

void removeDuplicates(Node *head){
    if(head==nullptr || head->next==nullptr){
        return;
    }
    Node *previous=head;
    Node *current=head->next;
    while(current!=nullptr){
        if(previous->data==current->data){
            current=current->next;
        }else{
            previous->next=current;
            previous=current;
            current=current->next;
        }
    }
}

void removeDuplicatesOfLL(Node *head){
    if(head==nullptr || head->next==nullptr){
        return;
    }
    Node *node=head;
    while(node->next!=nullptr){
        if(node->data==node->next->data){
            node->next=node->next->next;
        }else{
            node=node->next;
        }
    }
}
int main(){
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // removeDuplicates(list.head);
    removeDuplicatesOfLL(list.head);

    list.display();


    return 0;
}