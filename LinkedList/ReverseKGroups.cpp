#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

// algorithm must be redesigned from reverse part of the linked list to return a null pointer when index reaches out of bounds
Node* getNode(Node *head,int index){
    Node* temp=head;
    while(index>0 && temp!=nullptr){
        temp=temp->next;
        index--;
    }
    return temp;
}
void inPlaceReversalSubList(Node *first,Node *last){
    if(first==nullptr || first->next==nullptr){
        return;
    }
    Node *previous=nullptr;
    Node *current=first;
    Node *next=first->next;

    while(previous!=last){
        current->next=previous;
        previous=current;
        current=next;
        if(next!=nullptr){
            next=next->next;
        }
    }
}

Node* reversePartOfLL(Node *head,int start,int end){
    Node *first=getNode(head,start);
    Node *last=getNode(head,end);
    if(first==nullptr || last==nullptr){
        // index out of bounds
        return nullptr;
    }
    // reverse by considering 4 cases
    if(first==head && last->next==nullptr){
        inPlaceReversalSubList(first,last);
        return last;
    }else if(first==head && last->next!=nullptr){
        Node *after=getNode(head,end+1);
        inPlaceReversalSubList(first,last);
        first->next=after;
        return last;
    }else if(last->next==nullptr){
        Node *before=getNode(head,start-1);
        inPlaceReversalSubList(first,last);
        before->next=last;
    }else{
        Node *before=getNode(head,start-1);
        Node *after=getNode(head,end+1);
        inPlaceReversalSubList(first,last);
        before->next=last;
        first->next=after;
    }
    return head;
}
Node* reverseKGroupsLL(Node *head,int k){
    int start=0;
    int end=k-1;
    //Note : after first reversal node acts as head
    Node *node=reversePartOfLL(head,start,end);
    if(node==nullptr){
        return head;
    }
    Node *temp=node;
    while(temp!=nullptr){
        start+=k;
        end+=k;
        temp=reversePartOfLL(node,start,end);
    }
    return node;
}

int main(){
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60
    int k=4;
    list.head=reverseKGroupsLL(list.head,k);

    list.display();
    // 20 -> 10 -> 40 -> 30 -> 60 -> 50 for k=2
    return 0;
}