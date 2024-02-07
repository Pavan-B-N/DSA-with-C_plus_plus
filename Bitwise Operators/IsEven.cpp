// package BitwiseOperators;

//find whether the given number is even 
//4 - 100 
//5 - 101
//we can notice that for odd number the first bit (2^0)th bit is set to 1
//performing AND operation with the given number and with 1 yields 0 or 1
//numm & 1 == 1 ? odd : even


#include <iostream>
using namespace std;

//using lsb
int isEven(int n){
    return (n&1)==0;
}
// using xor operation
// 4 ^ 1 = 101 =5
// so for even res>n
// i.e if res > n then it's even else its odd
int isEvenUsingXor(int n){
    int res=n^1;
    return res>n;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int res;
    res=isEven(n);
    // res=isEvenUsingXor(n);
    cout<<(res==0 ? "False" : "True");
    return 0;
}