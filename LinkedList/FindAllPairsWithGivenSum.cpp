/*
1->2->3->4->9
sum=5

ouput=(1,4) and (2,3)

g++ .\DoublyLinkedList.cpp .\FindAllPairsWithGivenSum.cpp -o .exe
*/
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

// o(n^2)
void printAllPairs(Node *head,int target){
    Node *outer=head;
    while(outer!=nullptr && outer->data<target ){
        Node *inner=outer->next;
        while(inner!=nullptr && outer->data+inner->data<=target){
            if(outer->data+inner->data==target){
                cout<<"{ "<<outer->data<<", "<<inner->data<<" }, ";
            }
            inner=inner->next;
        }
        outer=outer->next;
    }
}

// two pointer method o(n)
void printAllPairs2(Node *head,Node *tail,int target){
    //head != nullptr && tail != nullptr && head != tail && head->prev != tail && 
    while(head->data<tail->data){
        int sum=head->data+tail->data;
        if(sum==target){
            cout<<"{ "<<head->data<<", "<<tail->data<<" }, ";
            head=head->next;
            tail=tail->prev;
        }else if(sum<target){
            head=head->next;
        }else{
            tail=tail->prev;
        }
    }
}

int main(){
    DoublyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(9);
    list.display();

    // printAllPairs(list.head,5);
    printAllPairs2(list.head,list.tail,5);

    return 0;
}

