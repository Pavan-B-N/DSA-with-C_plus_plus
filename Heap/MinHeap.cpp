#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size = 0;

    // O(logn) for bottom-up reheapification
    void insert(int val) {
        size++;
        arr[size] = val;
        bottomUpReheapify();
    }

    void bottomUpReheapify() {
        int index = size;
        while (index > 1 && arr[index] < arr[index / 2]) {
            swap(arr[index], arr[index / 2]);
            index = index / 2;
        }
    }

    void deleteMin() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        topDownReheapify();
    }

    void topDownReheapify() {
        int k = 1;
        while (2 * k <= size) {
            int j = 2 * k;  // left child
            if (j < size && arr[j] > arr[j + 1]) {
                j++;  // right child is smaller
            }
            if (arr[k] <= arr[j]) {
                break;
            }
            swap(arr[k], arr[j]);
            k = j;
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap minHeap;
    minHeap.insert(9);
    minHeap.insert(3);
    minHeap.insert(6);
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(5);
    minHeap.insert(4);

    minHeap.print();

    minHeap.insert(10);
    minHeap.print();

    minHeap.deleteMin();
    minHeap.print();

    return 0;
}
