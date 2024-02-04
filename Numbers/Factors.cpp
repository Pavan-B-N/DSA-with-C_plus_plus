#include <iostream>
#include <cmath>
using namespace std;

void factors(int n){
    for(int i=1;i<=(int)sqrt(n);i++){
        if(n%i==0){
            cout<<(i)<<" "<<(n/i)<<" ";
        }
    }
}

int main(){
    int n=20;
    factors(n);
    return 0;
}