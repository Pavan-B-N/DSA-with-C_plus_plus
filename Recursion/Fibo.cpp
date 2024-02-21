//0,1,1,2,3,5,8,13,21
#include <iostream>
using namespace std;

//Time complexity : (> exponential) or (golden ratio raise to power)
int fibo(int n){
    //base condition
    if(n<=1){
        return n;
    }
    //recurence relation
    return fibo(n-1)+fibo(n-2);
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<fibo(n)<<endl;
    return 0;
}