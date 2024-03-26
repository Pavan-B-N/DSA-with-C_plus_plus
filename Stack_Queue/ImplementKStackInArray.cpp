/*
Explanation:
top array stores the element or top index of each stack
so from top index we can get the next element which is in the stack using next array
next array contains index to next element until stack becomes empty at the end which is represented as -1
*/
#include <iostream>
#include <climits>
using namespace std;

// hard problem
// Time Complexity: O(N), as we are using a loop to traverse N times.
// Auxiliary Space: O(N), as we are using extra space for the stack.
class kStacks {
    int *arr;
    int *top;
    int *next;
    int n, k;
    int free;

public:
    kStacks(int k, int n) {
        this->k = k;
        this->n = n;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        for (int i = 0; i < k; i++)
            top[i] = -1;
        free = 0;
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
    }

    bool isFull() {
        return (free == -1);
    }

    void push(int item, int sn) {
        if (isFull()) {
            cout << "\nStack Overflow\n";
            return;
        }

        int i = free;
        //update index of free slot to index of next slot in free list
        free = next[i];
        next[i] = top[sn];
        top[sn] = i;
        // put the item in an array
        arr[i] = item;
    }

    void display(int n){
        int i=top[n];
        cout<<"-------"<<endl;
        while(i!=-1){
            cout<<" | "<<arr[i]<<" | "<<endl;
            i=next[i];
        }
        cout<<"-------"<<endl<<endl;;

    }

    int pop(int sn) {
        if (isEmpty(sn)) {
            cout << "\nStack Underflow\n";
            return INT_MAX;
        }

        int i = top[sn];
        top[sn] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }

    bool isEmpty(int sn) {
        return (top[sn] == -1);
    }
};

int main() {
    int k = 3, n = 10;
    kStacks ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
    ks.pop(1);
    ks.pop(1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    ks.display(0);
    ks.display(1);
    ks.display(2);


    // cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    // cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    // cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}
