#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverse(string &str){
    stack<char> charStack;

    for (char ch : str) {
        charStack.push(ch);
    }

    for (int i = 0; i < str.length(); i++) {
        str[i] = charStack.top();
        charStack.pop();
    }
}
int main() {
    string str = "Hello";
    cout << str << endl;

    reverse(str);

    cout << str << endl;

    return 0;
}

/*
// c program based
void reverse(char *str){
    stack<char> charStack;
    for(int i=0;str[i]!='\0';i++){
        charStack.push(str[i]);
    }

    for(int i=0;str[i]!='\0';i++){
        int top=charStack.top();
        charStack.pop();
        str[i]=top;
    }
}

int main(){
    char str[]="Hello";
    cout<<str<<endl;
    reverse(str);
    cout<<str<<endl;
    return 0;
}

*/