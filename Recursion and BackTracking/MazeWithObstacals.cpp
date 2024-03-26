/*
boolean matrix represent the maze if it is false means there is a obstacle
if we land on obstacle stop recursion
*/
#include <iostream>
#include <vector>
using namespace std;

// right and down is allowed
// from (0,0) to destination
void printPathsWithObstacles(string p,int row,int col,vector<vector<bool>> &maze){
    if(row==maze.size()-1 && col==maze[0].size()-1){
        cout<<p<<endl;
        return;
    }
    // if obstacle hit stop recursion for that path
    if(maze[row][col]==false){
        return;
    }
    if(row< maze.size()-1){
        printPathsWithObstacles(p+"D",row+1,col,maze);
    }
    if(col< maze[0].size()-1){
        printPathsWithObstacles(p+"R",row,col+1,maze);
    }
}

/*
All the cells which are visted make them false
*/
void pathAllDirections(string p,int row,int col,vector<vector<bool>> &maze){
    if(row==maze.size()-1 && col==maze[0].size()-1){
        cout<<p<<endl;
        return;
    }
    // if obstacle hit stop recursion for that path
    if(maze[row][col]==false){
        return;
    }
    // visited
    maze[row][col]=false;

    if(row< maze.size()-1){
        pathAllDirections(p+"D",row+1,col,maze);
    }
    if(col< maze[0].size()-1){
        pathAllDirections(p+"R",row,col+1,maze);
    }

    if(row>0){
        pathAllDirections(p+"U",row-1,col,maze);
    }

    if(col>0){
        pathAllDirections(p+"L",row,col-1,maze);
    }

    // restore to original state by backtracing
    maze[row][col]=true;
}

int main(int argc, char const *argv[])
{
    vector<vector<bool>> maze={
        {true,true,true},
        {true,true,true},
        {true,true,true},
    };

    // printPathsWithObstacles("",0,0,maze);
    pathAllDirections("",0,0,maze);


    return 0;
}
