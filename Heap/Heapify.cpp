#include <iostream>
#include <vector>
using namespace std;

// build maxHeap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Swap
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// heapify for building min heap
void buildMinHeap(vector<int>& arr, int n, int i) {
    int smallest = i;  // Initialize smallest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);  // Swap
        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

// Example usage
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    // Heapify the entire array
    for (int i = n / 2 - 1; i >= 0; i--){
        // heapify(arr, n, i);
        buildMinHeap(arr,n,i);
    }
      

    // Print the heapified array
    cout << "Heapified array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
