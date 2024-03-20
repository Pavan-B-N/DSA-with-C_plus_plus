// g++ .\SinglyLinkedList.cpp .\MergeKSortedLL.cpp -o .exe

// important question
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include "SinglyLinkedList.h"
using namespace std;

// time complexity = (n*k)log(n*k)
// space complexity = o(n*k)
Node* mergeKSortedLL(vector<Node*> list){
    vector<int> arr;
    for(int i=0;i<list.size();i++){
        Node* temp=list[i];
        while(temp!=nullptr){
            arr.push_back(temp->data);
            temp=temp->next;
        }
    }

    sort(arr.begin(),arr.end());;

    Node* dummy=new Node(0);
    Node *tail=dummy;
    for(int i=0;i<arr.size();i++){
        Node* node=new Node(arr[i]);
        tail->next=node;
        tail=tail->next;
    }
    return dummy->next;
}


// aproach two merge two list at a time
Node* mergeLL(Node *list1,Node *list2){
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
    tail->next = (list1 != nullptr) ? list1 : list2;
    return head->next;
}

Node* mergeKSortedLL2(vector<Node*> list){
    Node* head1=list[0];
    for(int i=1;i<list.size();i++){
        head1=mergeLL(head1,list[i]);
    }
    return head1;
}

// Custom comparator for Node pointers
struct NodeComparator {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->data > rhs->data; // Min heap comparison
    }
};

// Function to merge k sorted linked lists using min heap
Node* mergeKLists(vector<Node*>& lists) {
    // Define min heap for Node pointers
    priority_queue<Node*, vector<Node*>, NodeComparator> minHeap;

    // Push the head nodes of all lists into the min heap
    for (Node* head : lists) {
        if (head) {
            minHeap.push(head);
        }
    }

    // Dummy node to simplify code
    Node* dummy = new Node(0);
    Node* tail = dummy;

    // Merge lists
    while (!minHeap.empty()) {
        Node* minNode = minHeap.top();
        minHeap.pop();
        tail->next = minNode;
        tail = tail->next;

        if (minNode->next) {
            minHeap.push(minNode->next);
        }
    }

    return dummy->next;
}


int main()
{
    SinglyLinkedList list1;
    list1.insertAtEnd(2);
    list1.insertAtEnd(4);
    list1.insertAtEnd(6);

    SinglyLinkedList list2;
    list2.insertAtEnd(1);
    list2.insertAtEnd(5);

    SinglyLinkedList list3;
    list3.insertAtEnd(1);
    list3.insertAtEnd(1);
    list3.insertAtEnd(3);
    list3.insertAtEnd(7);

    SinglyLinkedList list4;
    list4.insertAtEnd(8);

    vector<Node*> list={list1.head,list2.head,list3.head,list4.head};

    SinglyLinkedList res;
    res.head=mergeKSortedLL(list);
    // res.head=mergeKLists(list);
    res.display();
    return 0;
}