//num1=20 num2=30
//represent both number using single number
//so that
//modules given num1
//division gives num2

#include <iostream>
using namespace std;

int singleRepresentation(int a,int b){
    int max=a+b;
    return a+(b%max)*max;
}

int main(){
    int a=10;
    int b=20;
    int res=singleRepresentation(a,b);
    int max=a+b;
    cout<<"a="<<a<<" and b="<<b<<" both can be represented as "<<res<<endl;

    cout<<"A="<<(res%max)<<endl;
    cout<<"B="<<(res/max)<<endl;
}