#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;
// https://leetcode.com/problems/merge-two-sorted-lists/submissions/1171239779/?envType=study-plan-v2&envId=top-interview-150
/*
Execution
 g++ .\SinglyLinkedList.cpp .\MergeTwoSortedLL.cpp -o .exe
*/
Node* merge(Node *list1,Node *list2){
    Node *head=new Node(0);
    Node *tail=head;
    while(list1!=nullptr && list2!=nullptr){
        if((list1->data)<(list2->data)){
            tail->next=list1;
            list1=list1->next;
        }else{
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;
    }
    if(list1!=nullptr){
        tail->next=list1;
    }else{
        tail->next=list2;
    }
    return head->next;
}