//find number of occurances of a given digit in a number
//n=1385757879; digit=7;
//output=3;

#include <iostream>
using namespace std;

int count(int num,int digit){
    int c=0;
    while(num>0){
        int lastdigit=num%10;
        num=num/10;
        if(lastdigit==digit){
            c++;
        }
        
    }
    return c;
}
int main(){
    int n=1385757879;
    int digit=7;
    int res=count(n,digit);
    cout<<res<<endl;
    return 0;
}