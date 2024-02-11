#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

/*
Execution:
g++ SinglyLinkedList.cpp FindNthNodeFromEndOfLL.cpp -o .exe
./.exe
*/

/*
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {};
};
*/

int findFromEnd(Node *head,int n){
    Node *slow=head;
    Node *fast=head;

    // first move the slow pointer n times
    while(n>=0 && fast!=nullptr){// if we don't want with respect to index just change the n>=0 to n>0
        fast=fast->next;
        n--;
    }

    // now move both slow and fast pointer until fast pointer reaches nullptr 
    while(fast!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }

    return slow->data;
}

int main(){
    SinglyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);

    list.display();

    int res=findFromEnd(list.head,2);
    cout<<"result : "<<res<<endl;

    return 0;
}