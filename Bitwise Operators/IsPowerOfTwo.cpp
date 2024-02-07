#include <iostream>
using namespace std;

int isPowerOf2(int n){
    if(n<=0){
        return 0;
    }
    return (n&(n-1))==0;
}

int main(){
    int n=16;
    int res=isPowerOf2(n);
    cout<<(res==0 ? "False" : "True");
    return 0;
}