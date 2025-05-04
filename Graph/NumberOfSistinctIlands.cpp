// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis,
             vector<pair<int, int>> &vec, int baseRow, int baseCol)
    {
        vis[row][col] = 1;
        vec.push_back({row - baseRow, col - baseCol});

        int n = grid.size();
        int m = grid[0].size();

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] && grid[newRow][newCol] == 1)
            {
                dfs(newRow, newCol, grid, vis, vec, baseRow, baseCol);
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;

        cout << "~" << "\n";
    }
}
// } Driver Code Ends