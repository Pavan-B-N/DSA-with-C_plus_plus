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

        solve(0,board,ans,n);

        return ans;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }

    bool isSafe(int row,int col,vector<string> &board,int n){
        // out of 8 directions
        // top and down is not required as we are visiting each column exactly onec
        // right, right top diagonal and right bottom diagonal also not required as we haven't visited tehm yet
        // so we just need to check 3 directions out of 8
        // left, left top diagonal, left bottom diagonal
        int actualRow=row;
        int actualCol=col;

        // left top diagonal (row--,col--)
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                // queen attacks
                return false;
            }
            row--;
            col--;
        }

        row=actualRow;
        col=actualCol;
        // left (row, col--)
        while(col>=0){
            if(board[row][col]=='Q'){
                // queen attacks
                return false;
            }
            col--;
        }

        row=actualRow;
        col=actualCol;
        // left botoom diagonal(row++,col--)
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                // queen attacks
                return false;
            }
            row++;
            col--;
        }

        return true;
    }
    
};