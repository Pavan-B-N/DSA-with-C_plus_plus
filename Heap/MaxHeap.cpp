#include <iostream>
using namespace std;

class heap{
public:
    int arr[100];
    int size=0;

    // o(logn) for botttomUpReHeapify
    void insert(int val){
        size++;
        arr[size]=val;
        botttomUpReHeapify();
    }

    // o(logn)
    void botttomUpReHeapify(){
        int index=size;
        while(index>1 && arr[index]>arr[index/2]){
            swap(arr[index],arr[index/2]);
            index=index/2;
        }
    }

    void deleteMax(){
        if(size==0){
            cout<<"heap is empty"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        topdownReheapify();
    }
    void topdownReheapify(){
        int k=1;
        while(2*k<=size){
            int j=2*k;//children
            if(j<size && arr[j]<arr[j+1]){
                j++;
            }
            if(arr[k]>arr[j]){
                break;
            }
            swap(arr[k],arr[j]);
            k=j;
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap maxHeap;
    maxHeap.insert(9);
    maxHeap.insert(3);
    maxHeap.insert(6);
    maxHeap.insert(2);
    maxHeap.insert(1);
    maxHeap.insert(5);
    maxHeap.insert(4);

    maxHeap.print();

    maxHeap.insert(10);
    maxHeap.print();

    maxHeap.deleteMax();
    maxHeap.print();

    return 0;
}