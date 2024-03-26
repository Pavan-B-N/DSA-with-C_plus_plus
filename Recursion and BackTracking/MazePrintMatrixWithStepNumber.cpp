#include <iostream>
#include <vector>
using namespace std;

/*
All the cells which are visted make them false
*/

void printMatrix(vector<vector<int>> &mat){
    cout<<"------------"<<endl;
    for(auto &arr:mat){
        for(auto &ele:arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<"------------"<<endl<<endl;
}
void pathAllDirections(string p,int row,int col,vector<vector<bool>> &maze,vector<vector<int>> &path,int step){
    if(row==maze.size()-1 && col==maze[0].size()-1){
        path[row][col]=step;
        cout<<p<<endl;
        printMatrix(path);
        return;
    }
    // if obstacle hit stop recursion for that path
    if(maze[row][col]==false){
        return;
    }
    // visited
    maze[row][col]=false;
    path[row][col]=step;

    if(row< maze.size()-1){
        pathAllDirections(p+"D",row+1,col,maze,path,step+1);
    }
    if(col< maze[0].size()-1){
        pathAllDirections(p+"R",row,col+1,maze,path,step+1);
    }

    if(row>0){
        pathAllDirections(p+"U",row-1,col,maze,path,step+1);
    }

    if(col>0){
        pathAllDirections(p+"L",row,col-1,maze,path,step+1);
    }

    // restore to original state by backtracing
    maze[row][col]=true;
    path[row][col]=0;
}

int main(int argc, char const *argv[])
{
    vector<vector<bool>> maze={
        {true,true,true},
        {true,true,true},
        {true,true,true},
    };
    vector<vector<int>> path(maze.size(), vector<int>(maze[0].size(), 0));

    pathAllDirections("",0,0,maze,path,1);


    return 0;
}
