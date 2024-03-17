//for the given array return how many of them contains even number of digits
/*
12 = 2 is even number of digits
123 = 3 is odd of digits
*/
#include <iostream>
#include <cmath>

using namespace std;

int len_num(int n){
    // because log10(0) is undefined
    if(n==0){
        return 1;
    }
    return floor(log10(n))+1;
}
int findEvenDigitsLength(int arr[],int n){
    int counter=0;
    for(int i=0;i<n;i++){
        int l=len_num(arr[i]);
        if(l%2==0){
            counter++;
        }
    }
    return counter;
}

int main(){
    int arr[]={ 1, 20, 0, 9, 2, -60, -50, -10 };
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=findEvenDigitsLength(arr,n);
    cout<<count;
    return 0;
}