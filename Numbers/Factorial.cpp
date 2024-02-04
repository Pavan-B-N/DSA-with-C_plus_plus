#include <iostream>
using namespace std;
//using recurrsion
int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

//using iteration
int factorial(int n){
    int f=1;
    while(n>0){
        f*=n;
        n--;
    }
    return f;
}

int main(){
    int num=5;
    int res=fact(num);
    cout<<res<<endl;
    res=factorial(num);
    cout<<res<<endl;
    return 0;
}