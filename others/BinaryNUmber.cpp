#include <iostream>
using namespace std;
int binary_number(string str){
    if(str==""){
        return -1;
    }
    int res=(int)(str[0]-'0');
    char ch;
    for(int i=1;i<str.length();i+=2){
        ch=str[i];
        int nextNum=(int)(str[i+1]-'0');
        switch(ch){
            case 'A':{
                res&=nextNum;
                break;
            }
            case 'B':{
                res|=nextNum;
                break;
            }
            case 'C':{
                res^=nextNum;
                break;
            }
        }
    }
    return res;
}

int main(){
    cout<<binary_number("1C0C1C1A0B1");
    return 0;
}