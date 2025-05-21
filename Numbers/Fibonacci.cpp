// 0 1 1 2 3 5 8 13
#include <iostream>
using namespace std;

// using recursion find nth fibonnaci number
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

// using iteration
void printFiboSeries(int n){
    int a=0;
    int b=1;
    for(int i=1;i<=n;i++){
        cout<<a<<" ";
        int temp=a+b;
        a=b;
        b=temp;
    }
}

int main(){
    int n=12;
    printFiboSeries(n);
    cout<<fibo(n-1)<<endl;
    return 0;
}