#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;
/*
g++ .\SinglyLinkedList.cpp .\RemoveDuplicatesFromUnsortedLL.cpp
./a or ./a.exe
*/
void removeDuplicatesForUnsortedLL(Node *head){
    Node *outer=head;
    while(outer!=nullptr){
        Node *preInner=outer;
        Node *inner=outer->next;
        while(inner!=nullptr){
            if(outer->data==inner->data){
                preInner->next=preInner->next->next;
            }else{
                preInner=inner;
            }
            inner=inner->next;
        }
        outer=outer->next;
    }
}
int main(){
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.insertAtEnd(40);

    // removeDuplicates(list.head);
    removeDuplicatesForUnsortedLL(list.head);

    list.display();


    return 0;
}