/*
Rotate a matrix by 90 degree in clockwise direction without using any extra space

Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3

*/
#include <iostream>
#include <vector>
using namespace std;

void transpose_matrix(vector<vector<int>> &matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=i;j<matrix[i].size();j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

void reverse_array(vector<int> &arr){
    int left=0;
    int right=arr.size()-1;
    while(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
}


void rotate90_degree(vector<vector<int>> &matrix){
    transpose_matrix(matrix);
    for(auto &arr:matrix){
        reverse_array(arr);
    }
}

void printMatrix(vector<vector<int>> &matrix){
 for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};

    printMatrix(matrix);
    rotate90_degree(matrix);
    printMatrix(matrix);
    return 0;
}