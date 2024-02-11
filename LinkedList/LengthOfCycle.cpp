#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

/*
Execution
g++ .\CircularLinkedList.cpp .\LengthOfCycle.cpp -o .exe
*/
int lengthOfCycle(Node *head){
    Node *slow=head;
    Node *fast=head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            //cycle detected
            //keep fast pointer in its place and let slow pointer to move until it will back to same posittion
            int n=0;
            do{
                slow=slow->next;
                n++;
            }while(slow!=fast);
            return n;
        }
    }
    return -1;
}

int main(){
    CircularLinkedList clist;
    clist.insertAtEnd(10);
    clist.insertAtEnd(20);
    clist.insertAtEnd(30);
    clist.insertAtEnd(40);

    cout<<"Length: "<<lengthOfCycle(clist.head)<<endl;
    return 0;
}