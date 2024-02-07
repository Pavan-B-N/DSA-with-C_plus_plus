// find a^b using bitwise operators
#include <iostream>
using namespace std;
int pow(int a,int b){
    int base=a;
    int ans=1;
    while(b>0){
        int lsb=b&1;
        if(lsb==1){
            ans*=base;
        }
        base*=base;
        // b>>=1;
        b=b>>1;
    }
    return ans;
}

int main(){
    int res=pow(2,3);
    cout<<res;
    return 0;
}