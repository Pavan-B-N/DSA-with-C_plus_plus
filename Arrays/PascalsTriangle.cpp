// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
#include <iostream>
using namespace std;

void printPascalsTriangle(int n)
{
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
    }

    // print the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    printPascalsTriangle(5);
    return 0;
}