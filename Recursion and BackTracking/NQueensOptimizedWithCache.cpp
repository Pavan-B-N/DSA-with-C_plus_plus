// https://leetcode.com/problems/n-queens/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string rowInBoard(n,'.');
        for(int i=0;i<n;i++){
            // by default no queens are placed
            board[i]=rowInBoard;
        }

        // cache method to store if there is a queen in left, leftUpperDiagonal, leftLowerDiagonal
        vector<int> left(n,0), leftUpperDiagonal(2*n-1,0),leftLowerDiagonal(2*n-1,0);
        
        solve(0,board,ans,n,left,leftUpperDiagonal,leftLowerDiagonal);

        return ans;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n,
        vector<int> &left,vector<int> &leftUpperDiagonal,vector<int> &leftLowerDiagonal
    ){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,left,leftUpperDiagonal,leftLowerDiagonal)){
                board[row][col]='Q';
                left[row]=1;
                leftLowerDiagonal[row+col]=1;
                leftUpperDiagonal[n-1+col-row]=1;
                solve(col+1,board,ans,n,left,leftUpperDiagonal,leftLowerDiagonal);

                // backtrack
                board[row][col]='.';
                left[row]=0;
                leftLowerDiagonal[row+col]=0;
                leftUpperDiagonal[n-1+col-row]=0;
            }
        }
    }

    bool isSafe(int row,int col,int n,
        vector<int> &left,vector<int> &leftUpperDiagonal,vector<int> &leftLowerDiagonal
    ){
        // 0 indicates that no one occupaied
        return left[row]==0 && leftUpperDiagonal[n-1+col-row]==0 && leftLowerDiagonal[row+col]==0;    
    }
    
};