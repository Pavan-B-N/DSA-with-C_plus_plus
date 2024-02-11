#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    //constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList{
private:
    Node *head;
    Node *tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    // Destructor to free the memory occupied by the doubly linked list
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtFirst(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }

    void insertAtEnd(int value){
        Node *newNode=new Node(value);
        if(tail==nullptr){
            head=tail=newNode;
            return;
        }
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
    void removeAtFirst(){
        if(head!=nullptr){
            Node *temp=head;
            head=head->next;
            if(head!=nullptr){
                head->prev=nullptr;
            }else{
                tail=nullptr;
            }
            delete temp;
        }
    }
    void removeAtEnd(){
        if(tail!=nullptr){
            Node *temp=tail;
            tail=tail->prev;
            if(tail!=nullptr){
                tail->next=nullptr;
            }else{
                head=nullptr;
            }
            delete temp;
        }
    }
    void display(){
        Node *temp=head;
        while(temp!=nullptr){
            cout<<(temp->data)<<" -> ";
            temp=temp->next;
        }
        cout<<" null "<<endl;
    }
};

int main(){
    DoublyLinkedList list;

    list.insertAtFirst(10);
    list.insertAtFirst(5);
    list.insertAtEnd(15);
    list.insertAtEnd(20);
    list.insertAtEnd(25);

    list.display();

    list.removeAtEnd();
    list.removeAtFirst();
    list.removeAtFirst();

    list.display();
    return 0;
}
