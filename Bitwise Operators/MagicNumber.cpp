//find the magic number for the given number
// 1 = 01 = 5
// 2 = 10 = 25
// 3 = 11 = 25+5=30
//magic number=sum(pow(5,k)) for the binary representaion of num;

//Amazon question

#include <iostream>
#include <cmath>
using namespace std;

int magicNumber(int n){
    int magicNum=0;
    int k=1;
    while(n>0){
        int lsb=n&1;
        if(lsb==1){
            double t=pow(5,k);
            magicNum+=t;
        }
        k++;
        n=n>>1;
    }
    return magicNum;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int m=magicNumber(n);
    cout<<"Magic Number of "<<n<<" is "<<m<<endl;
    return 0;
}