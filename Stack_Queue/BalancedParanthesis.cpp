#include <iostream>
#include <stack>
using namespace std;

//o(n)
bool isValidParenthesis(string &str){
    stack<char> charStack;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='(' ||  ch=='[' || ch=='{'){
            charStack.push(ch);
        }
        else if((charStack.top()=='(' && ch==')') || (charStack.top()=='{' && ch=='}') || (charStack.top()=='[' && ch==']') ){
            charStack.pop();
        }else{
            return false;
        }
    }
    if(!charStack.empty()){
        return false;
    }
    return true;
}

int main(){
    string str="[{()}]";
    // string str="[{()]";
    bool res=isValidParenthesis(str);//note in c++ boolean value is printed as 0 or 1 on console
    cout<<(res ? "True" : "False")<<endl;
    return 0;
}