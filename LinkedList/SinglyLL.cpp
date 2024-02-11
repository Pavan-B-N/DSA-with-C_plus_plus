#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int value):data(value),next(nullptr){};
};
class SinglyLinkedList{
private:
    Node *head;
public:
    // Constructor to initialize an empty linked list
    SinglyLinkedList() : head(nullptr) {}

     // Destructor to free the memory occupied by the linked list
    ~SinglyLinkedList(){
        while(head!=nullptr){
            Node *temp=head;
            head=head->next;
            delete temp;
        }
     }

    void insertAtFirst(int value){
        Node *newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
    void insertAtEnd(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=newNode;
        }
        else{
            // if we have tail node then we can easily perform this operation using 
            /*
                tail->next=newNode
            */
           //find the tailNode
           Node *tail=head;
           while(tail->next!=nullptr){
                tail=tail->next;
           }
           tail->next=newNode;
        }
    }
    void removeAtFirst(){
        if(head!=nullptr){
            Node *temp=head;
            head=head->next;
            delete temp;
        }
    }
    void removeAtEnd(){
        if(head==nullptr || head->next==nullptr){
            return removeAtFirst();
        }
        Node *temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;

    }
    void display(){
        Node *temp=head;
        while(temp!=nullptr){
            cout<<(temp->data)<<" -> ";
            temp=temp->next;
        }
        cout<<"null"<<endl;
    }
};

int main(){
    SinglyLinkedList list;

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
