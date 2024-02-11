#include <iostream>
#include "CircularLinkedList.h"
using namespace std;
// g++ .\CircularLinkedList.cpp .\MiddleOfLL.cpp -o .exe
Node *middle(Node *head)
{
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node *slow=head;
    Node *fast=head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != nullptr && fast->next != nullptr && fast != head && fast->next != head);
    
    return slow;
}

int main(){
    CircularLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    Node *mid=middle(list.head);
    cout<<"Data: "<<(mid->data)<<endl;

    return 0;
}