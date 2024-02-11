#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int value):data(value),next(nullptr){}
};

class CircularLL{
private:
    Node *head;

public:
    CircularLL():head(nullptr){}
    // Destructor to free the memory occupied by the circular linked list
    ~CircularLL(){
        Node *current=head->next;
        while(current!=head){
            Node *temp=current;
            current=current->next;
            delete temp;
        }
        delete head;//or current
    }

    void insertAtFirst(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=newNode;
            head->next=head;
        }else{
            //find tail
            Node *tail=head;
            while(tail->next!=head){
                tail=tail->next;
            }
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    void insertAtEnd(int value){
        Node *newNode=new Node(value);
        if(head==nullptr){
            head=newNode;
            newNode->next=head;
            return;
        }
        Node *tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=newNode;
        newNode->next=head;
    }

    void removeAtFirst(){
        if(head!=nullptr){
            // find tail
            Node *tail=head;
            while(tail->next!=head){
                tail=tail->next;
            }

            //if only one element
            if(head==tail){
                delete head;
                head=nullptr;
            }else{
                Node *temp=head;
                head=head->next;
                tail->next=head;
                delete temp;
            }
        }
    }

    void removeAtEnd(){
        if(head==nullptr){
            return;
        }
        // find tail
        Node *tail=head;
        Node *secondTail=nullptr;
        while(tail->next!=head){
            secondTail=tail;
            tail=tail->next;
        }
        
        if(secondTail==nullptr){ // or tail==head
            delete head;
            head=nullptr;
        }else{
            secondTail->next=head;
            delete tail;
        }
    }

    void display(){
        Node *temp=head;
        while(temp->next!=head){
            cout<<(temp->data)<<" -> ";
            temp=temp->next;
        }
        cout<<(temp->data)<<" -> "<<(head->data)<<"(head)"<<endl;
    }
};

int main(){
    CircularLL list;

    list.insertAtFirst(10);
    list.insertAtFirst(5);
    list.insertAtFirst(3);
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
