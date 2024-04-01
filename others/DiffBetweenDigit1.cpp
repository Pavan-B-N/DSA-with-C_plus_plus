/*
12 = 2-1 = 1
678 = 8-7,7-6 =1
*/

#include <iostream>
using namespace std;

int ans(int n){
    int r=n%10;
    n=n/10;
    while(n>0){
        if(r-n%10!=1){
            return 0;
        }
        r=n%10;
        n=n/10;
    }
    return 1;
}

int main(){
    int a=10;
    int b=1000;
    for(int i=a;i<=b;i++){
        int c=ans(i);
        if(c){
            printf("%d ",i);
        }
    }
    return 0;
}