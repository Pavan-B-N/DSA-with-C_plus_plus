#include <iostream>
using namespace std;
int main(){
    const int rows=5;
    const int cols=5;
    int arr[rows][cols]={
        {34,21,32,41,25},
        {14,42,43,14,31},
        {54,45,52,42,23},
        {33,15,51,31,35},
        {21,52,33,13,23}
    };
    //starting clue = 11
    int rowNo=1;
    int colNo=1;
    int ele=11;
    while(rowNo<=rows && colNo<=cols && arr[rowNo-1][colNo-1]!=ele){
        cout<<ele<<" ";
        ele=arr[rowNo-1][colNo-1];
        rowNo=ele/10;
        colNo=ele%10;
    }
    cout<<arr[rowNo-1][colNo-1];
    return 0;
}