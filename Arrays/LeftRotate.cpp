/*
arr[] = {1, 3, 5, 7, 9}
    k1 = 1
    k2 = 3
    k3 = 4
    k4 = 6
Output : 
    3 5 7 9 1
    7 9 1 3 5
    9 1 3 5 7
    3 5 7 9 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rightRotate(vector<int> &arr,int d){
    int n=arr.size();
    d=d%n;
    reverse(arr.begin(),arr.begin()+n);
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.begin()+n);
}
void leftRotate(vector<int> &arr,int d){
    int n=arr.size();
    d=d%n;
    reverse(arr.begin(),arr.begin()+n);
    reverse(arr.begin(),arr.begin()+(n-d));
    reverse(arr.begin()+(n-d),arr.begin()+n);
}
void printLeftRotationForm(vector<int> &arr,int d){
    int n=arr.size();
    d=d%n;
    for(int i=0;i<n;i++){
        cout<<arr[(d+i)%n]<<" ";
    }
}

int main(){
    vector<int> vec={1,2,3,4,5,6,7};
    // vector<int> vec={1, 3, 5, 7, 9};
    printLeftRotationForm(vec,2);
    cout<<endl;

    leftRotate(vec,2);
    for(auto &ele:vec){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}   