/*
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

Input matrix :
            0 1 1 1
            0 0 1 1
            1 1 1 1  // this row has maximum 1s
            0 0 0 0
Output: 2
*/

#include <iostream>
#include <vector>
using namespace std;

// binary search o(logn) time complexity
int firstIndex(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int minIndex = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            minIndex = mid;
            end = mid - 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return minIndex;
}
int rowWithMax1(vector<vector<int>> &matrix){
    int rowIndex=-1;
    int maxCount=-1;
    for(int i=0;i<matrix.size();i++){
        int fi=firstIndex(matrix[i],1);
        if(fi==-1){
            continue;
        }
        int count=matrix[i].size()-1-fi;
        if(count>maxCount){
            maxCount=count;
            rowIndex=i;
        }
    }
    return rowIndex;
}
int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    cout<<rowWithMax1(matrix);
    return 0;
}