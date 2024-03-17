#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

// g++ .\InterSectionOfTwoSortedLL.cpp .\SinglyLinkedList.cpp -o .exe
void interSection(Node *head1,Node *head2){
    Node *list1Ptr=head1;
    Node *list2Ptr=head2;

    while(list1Ptr!=nullptr && list2Ptr!=nullptr){
        if(list1Ptr->data==list2Ptr->data){
            cout<<list1Ptr->data<<" ";
            list1Ptr=list1Ptr->next;
            list2Ptr=list2Ptr->next;
        }else if(list1Ptr->data<list2Ptr->data){
            list1Ptr=list1Ptr->next;
        }else{
            list2Ptr=list2Ptr->next;
        }
    }
}
int main(){
    SinglyLinkedList list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);
    list1.display();

    SinglyLinkedList list2;
    list2.insertAtEnd(2);
    list2.insertAtEnd(3);
    list2.insertAtEnd(5);
    list2.display();


    interSection(list1.head,list2.head);
    return 0;
}