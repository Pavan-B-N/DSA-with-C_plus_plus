//find kth bit of a number
#include <iostream>
using namespace std;

// using least significant bit
int kthbit(int n,int k){
    int lsb=0;
    while(k>0){
        if(n==0){
            return 0;
        }
        lsb=n&1;
        n=n>>1;// right shift - decrease value
        k--;
    }
    return lsb;
}
//using mask of the given number
int kthBitUsingMask(int n,int k){
    //create a mask using left shift
    int mask=n<<(k-1);
    int res=n&mask;// res>=0
    return res==0 ? 0 : 1;
}

int main(){
    int n=3;
    int k=3;
    // int ans=kthbit(n,k);
    int ans=kthBitUsingMask(n,k);
    cout<<ans<<endl;
    return 0;
}