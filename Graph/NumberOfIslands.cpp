/*
https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

'0's (Water) and '1's(Land)

Given a binary 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 4 islands.

Example:

Input: mat[][] = {{1, 1, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {1, 0, 0, 1, 1},
                {0, 0, 0, 0, 0},
                {1, 0, 1, 0, 0}}
Output: 4
*/

// The number of calls to DFS() gives the number of connected components

#include <iostream>
#include <cstring>
using namespace std;

#define ROW 5
#define COL 5

// cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col, bool visited[][COL])
{
    // M[row][col] == 1
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}

// 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col, bool visited[][COL])
{
    // These arrays are used to get row and column numbers of 8 neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k],visited))
            DFS(M, row + rowNbr[k], col + colNbr[k],visited);
}

int countIslands(int M[][COL])
{

    bool visited[ROW][COL];

    // Initialize visited array to false
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            visited[i][j] = false;
        }
    }

    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j])
            {
                // visited yet, then new island found
                // Visit all cells in this island.
                DFS(M, i, j, visited);

                // and increment island count
                ++count;
            }

    return count;
}

// Driver code
int main()
{
    int M[][COL] = {{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(M);

    return 0;
}


/*

class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        int ROW=grid.size();
        int COL=grid[0].size();
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
        
    }
    
    void dfs(vector<vector<char>>& grid,int row,int col){
        
        int ROW=grid.size();
        int COL=grid[0].size();
        
        static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        grid[row][col]='0';//visited will be changed to 0
        
        for (int k = 0; k < 8; ++k){
             if (isSafe(grid, row + rowNbr[k], col + colNbr[k]))
                dfs(grid,row + rowNbr[k], col + colNbr[k]);
        }
           
    }
    
    bool isSafe(vector<vector<char>>& grid,int row,int col){
        int ROW=grid.size();
        int COL=grid[0].size();
        return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (grid[row][col]=='1');
    }
    
    
};

*/