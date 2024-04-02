#include <iostream>
#include <string>
using namespace std;

void trim(string &str){
    bool inWord=false;
    int index=0;
    for(char ch:str){
        if(ch!=' '){
            str[index++]=ch;
            inWord=true;
        }else if(inWord){
            str[index++]=' ';
            inWord=false;
        }
    }
     if(str[index-1]==' '){
        index--;
    }
    // Resize the string to remove any characters beyond index
    str.resize(index);
    // In C++, std::string objects are not null-terminated like C-style strings
}

int main()
{
    string str = "      hello       world          ";
    
    trim(str);

    cout << str << endl;
    return 0;
}
