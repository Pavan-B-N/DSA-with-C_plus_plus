// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
/*
implement a stack which will support the following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
*/
#include <iostream>
using namespace std;

// implemented using doubly linked list
class myStack {
    struct Node {
        int num;
        Node* next;
        Node* prev;

        Node(int num) { this->num = num; }
    };

    Node* head = NULL;
    Node* mid = NULL;
    int size = 0;

public:
    void push(int data) {
        Node* newNode = new Node(data);
        if (size == 0) {
            head = newNode;
            mid = newNode;
            size++;
            return;
        }

        newNode->prev = head;
        head->next = newNode;
        head = head->next; // always head is the top of the stack
        // if odd then only we need to move the mid pointer
        if (size % 2 == 1) {
            mid = mid->next;
        }
        size++;
    }

    int pop() {
        int data = -1;
        if (size != 0) {
            Node* toPop = head;
            data = toPop->num;
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else {
                head = head->prev;
                head->next = NULL;
                // if even number of nodes exists then go back
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
            }
            delete toPop;
            size--;
        }
        return data;
    }

    int findMiddle() {
        if (size == 0) {
            return -1;
        }
        return mid->num;
    }

    void deleteMiddle() {
        if (size != 0) {
            Node* toDelete = mid;
            if (size == 1) {
                head = NULL;
                mid = NULL;
            }
            else {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                // if size of list even go back else go next
                if (size % 2 == 0) {
                    mid = mid->prev;
                }
                else {
                    mid = mid->next;
                }
            }
            delete toDelete;
            size--;
        }
    }
};

int main() {
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}
