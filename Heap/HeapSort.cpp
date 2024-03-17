/*
Heapsort is a comparison-based sorting algorithm that uses a binary heap data structure to sort elements.

*/

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]); // Swap
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


// o(logn)
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    cout << "array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout<<endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
