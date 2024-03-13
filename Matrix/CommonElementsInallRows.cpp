/*
Common elements in all rows of a given matrix

Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.
*/
#include <iostream>
#include <unordered_map>
using namespace std;

// Specify number of rows and columns
#define M 4
#define N 5

// Function to print common elements in all rows of matrix
void printCommonElements(int mat[M][N])
{
    // Initialize an unordered map to store the count of occurrences of each element
    unordered_map<int, int> mp;

    // Initialize the count of elements in the first row
    for (int j = 0; j < N; j++)
        mp[(mat[0][j])] = 1;

    // Traverse the matrix starting from the second row
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // If element is present in the map and is not duplicated in the current row
            if (mp[(mat[i][j])] == i)
            {
                // Increment count of the element in map by 1
                mp[(mat[i][j])] = i + 1;

                // If this is the last row and count of the element is equal to M
                if (i == M - 1 && mp[(mat[i][j])] == M)
                    cout << mat[i][j] << " ";
            }
        }
    }
}

// Driver program to test above function
int main()
{
    int mat[M][N] =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };

    printCommonElements(mat);

    return 0;
}
