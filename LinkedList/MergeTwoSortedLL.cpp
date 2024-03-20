#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;
// https://leetcode.com/problems/merge-two-sorted-lists/submissions/1171239779/?envType=study-plan-v2&envId=top-interview-150
/*
Execution
 g++ .\SinglyLinkedList.cpp .\MergeTwoSortedLL.cpp -o .exe
*/
Node* mergeLL(Node *head1,Node *head2){
    Node *dummy=new Node(0);
    Node *tail=dummy;
    while(head1!=nullptr && head2!=nullptr){
        if((head1->data)<(head2->data)){
            tail->next=head1;
            head1=head1->next;
        }else{
            tail->next=head2;
            head2=head2->next;
        }
        tail=tail->next;
        
    }
    tail->next = (head1 != nullptr) ? head1 : head2;
    return dummy->next;
}

int main()
{
    SinglyLinkedList list1;
    list1.insertAtEnd(2);
    list1.insertAtEnd(4);
    list1.insertAtEnd(6);
    list1.display();

    SinglyLinkedList list2;
    list2.insertAtEnd(1);
    list2.insertAtEnd(5);
    list2.display();

    SinglyLinkedList res;
    res.head=mergeLL(list1.head,list2.head);
    res.display();
    return 0;
}