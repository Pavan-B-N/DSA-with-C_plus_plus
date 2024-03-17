
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

Node* getNodeAtIndex(Node *head,int index){
    while(head!=nullptr && index>0){
        index--;
        head=head->next;
    }
    return head;
}

// o(k)
Node* leftRotate(Node *head,Node *tail,int k){
    Node *start=getNodeAtIndex(head,k);
    if(start==nullptr){
        cout<<"rotation is not possible"<<endl;
        return head;
    }
    cout<<"Start="<<start->data<<endl;
    Node *startPre=start->prev;
    start->prev=nullptr;
    startPre->next=nullptr;
    tail->next=head;
    head->prev=tail;
    tail=startPre;
    return start;
}

int main(){
    DoublyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.display();

    list.head=leftRotate(list.head,list.tail,2);
    list.display();
    return 0;
}