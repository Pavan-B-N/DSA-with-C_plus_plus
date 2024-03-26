/*
------------
X Q X X
X X X Q
Q X X X
X X Q X
------------

------------
X X Q X
Q X X X
X X X Q
X Q X X
------------

Toatl Number of queens are : 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayboard(vector<vector<bool>> &board){
    cout<<"------------"<<endl;
    for(auto row:board){
        for(auto ele:row){
            char temp=ele ? 'Q' : 'X';
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    cout<<"------------"<<endl<<endl;
}
bool isSafe(vector<vector<bool>> board, int row,int col){
    //chech vertical row
    for(int i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }
    }

    //diagonal left
    int maxLeft = min(row, col); 
    for (int i = 1; i <= maxLeft; i++) {
        if (board[row - i][col - i]) {
            return false;
        }
    }

    //diagonal right
    int maxRight = min(row, static_cast<int>(board.size() - 1 - col));
    for (int i = 1; i <= maxRight; i++) {
        if (board[row - i][col + i]) {
            return false;
        }
    }

    return true;
}
// int queens(bool** board, int row)
// Time complexity = o(N!)
int queens(vector<vector<bool>> board, int row){
    if(row==board.size()){
        displayboard(board);
        return 1;
    }
    int count=0;
    // placing the queeen and checking for every row and col
    for(int col=0;col<board.size();col++){
        // place the queen only if it is safe
        if(isSafe(board,row,col)){
            board[row][col]=true;
            count+=queens(board,row+1);
            //revert changes while backtracking
            board[row][col]=false;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int boardSize=4;// or number of queens need to be placed
    vector<vector<bool>> board(boardSize, vector<bool>(boardSize, false));

    cout<<"Toatl Number of queens are : "<<queens(board,0);
    return 0;
}
