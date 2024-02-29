#include <iostream>
#include <algorithm>
using namespace std;

string convertToBase(int n,int base){
    string res="";
    while(n>0){
       int remainder = n % base;
        res += (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        n /= base;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int n=17;
    int b=8;
    cout<<convertToBase(n,b);
    return 0;
}