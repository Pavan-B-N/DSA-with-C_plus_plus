#include <iostream>
using namespace std;
string moveHypensToFront(string str){
    string res="";
    int k=0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '-'){
            res="-"+res;
        }else{
            res+=str[k];
        }
        k++;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    string str="move-hyphens-to-front";
    cout<<moveHypensToFront(str)<<endl;
    return 0;
}
