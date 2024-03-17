#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

Node* getTail(Node* head) {
    if (!head) return nullptr;
    while (head->next!=nullptr) {
        head = head->next;
    }
    return head;
}

Node* partition(Node* head, Node* tail) {
    Node *pivot=head;
    Node *curr=head->next;
    Node *pre=head;
    while(curr!=tail->next){
        if(pivot->data > curr->data){
            swap(pre->next->data,curr->data);
            pre=pre->next;
        }
        curr=curr->next;
    }
    swap(pre->data,pivot->data);
    return pre;
}

void quickSortHelper(Node* head, Node* tail) {
    if(head==nullptr || tail==nullptr || head==tail){
        return;
    }
    Node *pivot=partition(head,tail);
    quickSortHelper(head,pivot);
    quickSortHelper(pivot->next,tail);
}

void quickSort(Node* head) {
    quickSortHelper(head, getTail(head));
}
int main(){
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(2);
    list.insertAtEnd(5);
    list.insertAtEnd(40);
    list.display();

    quickSort(list.head);
    list.display();
    return 0;
}