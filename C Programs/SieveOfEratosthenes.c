#include <stdio.h>

void printPrime(int n);

int main(){
    int n=100;
    printPrime(n);

    return 0;
}

// Time complexity = O(n log log n)
void printPrime(int n){
    int arr[n];
    for(int i=0;i<=n;i++){
        arr[i]=i;
    }
    // first make 1 to be zero
    arr[1]=0;
    for(int i=2;i*i<=n;i++){
        if(arr[i]!=0){
            // make multiples of i zero
            for(int j=i*i;j<=n;j+=i){
                arr[j]=0;
            }
        }
    }

    //print the array
    for(int i=2;i<=n;i++){
        if(arr[i]!=0){
            printf("%d ",arr[i]);
        }
    }
}