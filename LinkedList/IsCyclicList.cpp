#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

/*
Execution:
g++ CircularLinkedList.cpp IsCyclicList.cpp -o .exe
./.exe
*/
// Floyd's cycle detection algorithm
bool isCyclic(Node *head){
    Node *slow=head;
    Node *fast=head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main(){
    CircularLinkedList list;
    list.insertAtEnd(20);
    // it always false
    cout<<"SinglyLL "<<isCyclic(list.head)<<endl;

    return 0;
}