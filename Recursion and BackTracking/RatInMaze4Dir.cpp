// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1&selectedLang=python3
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        vector<string> ans;
        int n = maze.size();
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;  // early exit
        maze[0][0] = -1; // mark starting cell as visited
        getPossiblePaths(maze, "", ans, 0, 0);
        return ans;
    }

    void getPossiblePaths(vector<vector<int>> &maze, string path, vector<string> &ans, int row, int col)
    {
        int n = maze.size();
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // Direction vectors and labels
        vector<int> dx = {1, 0, 0, -1}; // Down, Left, Right, Up
        vector<int> dy = {0, -1, 1, 0};
        string dir = "DLRU";

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (isSafe(newRow, newCol, n, maze))
            {
                maze[newRow][newCol] = -1;// mark as visited
                getPossiblePaths(maze, path + dir[i], ans, newRow, newCol);
                maze[newRow][newCol] = 1; // backtrack and mark it back to not visited
            }
        }
    }

    bool isSafe(int row, int col, int n, vector<vector<int>> &maze)
    {
        return row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1;
    }
};
