#include <iostream>
using namespace std;

// right and down is allowed
// from (3,3) to (1,1)
int countPossiblePaths(int row,int col){
    if(row==1 || col==1){
        return 1;
    }
    int left=countPossiblePaths(row-1,col);
    int right=countPossiblePaths(row,col-1);
    return left+right;
}


// right and down is allowed
void printPaths(string p,int row,int col){
    if(row==1 && col==1){
        cout<<p<<endl;
        return;
    }
    if(row!=1){
        printPaths(p+"D",row-1,col);
    }
    if(col!=1){
        printPaths(p+"R",row,col-1);
    }
}

// right, down and diagonal is allowed
void printPaths2(string p,int row,int col){
    if(row==1 && col==1){
        cout<<p<<endl;
    }
    //diagonal
    if(row>1 && col>1){
        printPaths2(p+"d",row-1,col-1);
    }
    //down
    if(row!=1){
        printPaths2(p+"D",row-1,col);
    }
    //right
    if(col!=1){
        printPaths2(p+"R",row,col-1);
    }
}

// right, down and diagonal is allowed
int countPossiblePaths2(int row,int col){
    if(row==1 || col==1){
        return 1;
    }
    int left=countPossiblePaths2(row-1,col);//down
    int right=countPossiblePaths2(row,col-1);//right
    int diagnal=countPossiblePaths2(row-1,col-1);//diagonally
    return left+right+diagnal;
}

int main(int argc, char const *argv[])
{   
    //3*3 matrix
    int row=3;
    int col=3;
    
    // cout<<"possible paths are : "<<countPossiblePaths2(row,col)<<endl;

    // printPaths2("",3,3);

    return 0;
}
