/*
https://leetcode.com/problems/flood-fill/description/

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
*/
#include <iostream>
#include <vector>
using namespace std;

// s= starting pexel of row or col
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int ROW = image.size();
        int COL = image[0].size();
        if (sr < 0 || sr >= ROW || sc < 0 || sc >= COL || image[sr][sc] == newColor)
        {
            return image;
        }
        // Code here
        dfs(image, sr, sc, newColor);

        return image;
    }

    void dfs(vector<vector<int>> &image, int row, int col, int newColor)
    {
        static int rowNbr[] = {-1, 0, 0, 1};
        static int colNbr[] = {0, -1, 1, 0};

        int initialColor = image[row][col];

        image[row][col] = newColor;

        for (int i = 0; i < 4; i++)
        {
            if (isSafe(image, row + rowNbr[i], col + colNbr[i], initialColor))
            {
                dfs(image, row + rowNbr[i], col + colNbr[i], newColor);
            }
        }
    }

    bool isSafe(vector<vector<int>> &image, int row, int col, int initialColor)
    {
        int ROW = image.size();
        int COL = image[0].size();

        return (row >= 0 && row < ROW && col >= 0 && col < COL && image[row][col] == initialColor);
    }
};