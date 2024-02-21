/*
input: 300804
output: 3
*/
#include <iostream>
using namespace std;

int helper(int digit,int counter){
    if(digit==0){
        return counter;
    }
    int lastdigit=digit%10;
    lastdigit==0 && counter++ ;
    return helper(digit/10,counter);
}
int countZeros(int digit){
    return helper(digit,0);
}
int main(){
    int n=300804;
    cout<<countZeros(n)<<endl;
    return 0;
}