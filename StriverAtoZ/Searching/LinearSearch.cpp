#include <iostream>
using namespace std;
int main(){
    int arr[]={5,2,3,4,2};
    int n=5;

    int target=50;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"Target "<<target<<" found at index "<<i;
            break;
        }
    }
    cout<<"Target not found"<<endl;

    return 0;
}