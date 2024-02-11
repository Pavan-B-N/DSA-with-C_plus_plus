// 1 -> 2 -> 3 -> 4
// 1-> 2 , 3->4
#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

// returns a mid next element as head for another list i.e for 3
// 1 2 3 mid=1
// 1 2 3 4 mid=2
Node* spliceAtMid(Node *head){
    Node *slow=nullptr;//1x speed
    Node *fast=head;//2x speed
    while(fast!=nullptr && fast->next!=nullptr){
        slow=(slow!=nullptr) ? slow->next : head;
        fast=fast->next->next;
    }
    //slow is exactly at mid
    Node *midNext=slow->next;
    slow->next=nullptr;// splice
    return midNext;
}

int main(){
    SinglyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    spliceAtMid(list.head);

    list.display();

    return 0;
}