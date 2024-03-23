#include <iostream>
using namespace std;
void removeChar(string &str,char ch){
    int k=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=ch){
            str[k++]=str[i];
        }
    }
    // str[k]='\0';
    str.resize(k); 
}
int main(int argc, char const *argv[])
{
    string str="abbcaadb";
    cout<<str<<endl;
    removeChar(str,'b');
    cout<<str<<endl;
    return 0;
}
