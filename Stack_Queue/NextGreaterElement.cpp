/*
Input:
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ?
since it doesn't exist, it is -1.
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* Naive approach to find next greater element */
// o(n^2)
vector<int> findNGE_naive(int arr[], int n)
{
    vector<int> result(n, -1);

    // Iterate through each element
    for (int i = 0; i < n; ++i) {
        // For the current element, search for the next greater element
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) {
                // If found, update the result and break
                result[i] = arr[j];
                break;
            }
        }
    }

    return result;
}

// o(n)
vector<int> findNGE(int arr[], int n)
{
    vector<int> result(n, -1); // Initialize result vector with -1
    stack<int> s;

    // iterate for all elements
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] > arr[s.top()])
        {
            result[s.top()] = arr[i];
            s.pop();
        }
        // Push the current index onto the stack
        s.push(i);
    }

    return result;
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = findNGE(arr, n);

    cout << "Next greater elements for each element in the original array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
