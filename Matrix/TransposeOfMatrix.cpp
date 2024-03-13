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
    vector<vector<int>> matrix = {{10, 20, 30, 40},
                                {15, 25, 35, 45},
                                {27, 29, 37, 48},
                                {32, 33, 39, 50}};
                        
    printMatrix(matrix);
    transpose_matrix(matrix);
    printMatrix(matrix);
    
    return 0;
}