/*
Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x

dll= 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
x=17
output=2 triplets={2,6,9} and {4,5,8}
*/

#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

// o(n^2)
int countTriplets(Node *head, Node *tail, int target)
{
    Node *outer = head;
    int counter = 0;
    while (outer != nullptr)
    {
        Node *start = outer->next;
        Node *end = tail;

        while (start!=nullptr && end!=nullptr &&  start->data < end->data && start != end )
        {
            int sum = outer->data + start->data + end->data;
            if (sum == target)
            {
                counter++;
                cout << "{ " << outer->data << ", " << start->data << ", " << end->data << " }, ";
                end = end->prev;
                start = start->next;

            }
            else if (sum > target)
            {
                end = end->prev;
            }
            else
            {
                start = start->next;
            }
        }

        outer=outer->next;
    }

    return counter;
}

int main(){
    DoublyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    list.display();

    cout<<"Total Triplets are : "<<countTriplets(list.head,list.tail,17);
    return 0;
}