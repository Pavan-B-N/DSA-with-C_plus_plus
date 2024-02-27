#include <iostream>
using namespace std;
string removeChar(string str,char ch,string res){
    if(str==""){
        return res;
    }
    if(str[0]==ch){
        return removeChar(str.substr(1,str.size()),ch,res);
    }else{
      return removeChar(str.substr(1,str.size()),ch,res+str[0]);
    }
}
string removeChar(string str,char ch){
    return removeChar(str,ch,"");
}

int main(){
    string str="abbaaass";
    //remove a
    str=removeChar(str,'a');
    cout<<str<<endl;
    return 0;
}