// flip means reversing the each row
// invert means 0 becomes 1 and 1 becomes 0
/*
int arr[][] = {
        { 1, 0, 1 },
        { 0, 1, 1 },
        { 0, 1, 0 }
};
//output
// [0, 1, 0]
// [0, 0, 1]
// [1, 0, 1]
*/
#include <iostream>
using namespace std;
// In C++, arrays are a fixed-size contiguous block of memory, and the size of each dimension must be known at compile time.
// hence size of the second dimension must be specified
void flipAndInvert(int arr[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n / 2; j++)
        {
            // swap-to reverse
            int temp = arr[i][j] ^ 1;
            arr[i][j] = (arr[i][n - j - 1]) ^ 1;
            arr[i][n - j - 1] = temp;
        }
    }
}

int main()
{
    int arr[][3] = {
        {1, 0, 1},
        {0, 1, 1},
        {0, 1, 0}};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << " \n ------------ \n"
         << endl;

    flipAndInvert(arr, n);

    // print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}