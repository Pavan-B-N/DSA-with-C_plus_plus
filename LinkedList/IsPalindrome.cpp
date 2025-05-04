//check whether the given list is palindrome or not without modifying the original list
#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;
// g++ .\IsPalindrome.cpp .\SinglyLinkedList.cpp -o .exe

// return the mid
// 1 2 3 mid=1
// 1 2 3 4 mid=2

// Refer the new one from FAANG
Node* getMid(Node *head){
    if(head==nullptr || head->next==nullptr){
        head;
    }
    Node *slow=nullptr;
    Node *fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=(slow==nullptr) ? head : slow->next;
        fast=fast->next->next;
    }
    Node *midNext=slow->next;
    return midNext;
}
Node* inPlaceReversalLL(Node *head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node *previous=nullptr;
    Node *current=head;
    Node *next=head->next;

    while(current!=nullptr){
        current->next=previous;
        previous=current;
        current=next;
        if(next!=nullptr){
            next=next->next;
        }
    }
    return previous;
}
bool isPalindrome(Node *head){
    Node *mid=getMid(head);

    Node *head2=new Node(0);
    Node *tail=head2;
    //copy mid to tail elements to new list
    while(mid!=nullptr){
        tail->next=new Node(mid->data);
        tail=tail->next;
        mid=mid->next;
    }
    head2=head2->next;
    head2=inPlaceReversalLL(head2);

    //palindrome test
    // here we dont splice the mid so we can skip head!=nullptr condition but when mid is spliced its compuslsory
    while(head!=nullptr && head2!=nullptr){
        if(head->data!=head2->data){
            return false;
        }
        head=head->next;
        head2=head2->next;
    }
    return true;
}

int main(){
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.insertAtEnd(10);

    cout<<isPalindrome(list.head)<<endl;

    list.display();
    return 0;
}