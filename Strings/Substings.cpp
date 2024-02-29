#include <iostream>
using namespace std;
void substrings(string str){
    int length = str.length();

    for (int startIndex = 0; startIndex < length; startIndex++) {
        for (int len = 1; len <= length - startIndex; len++) {
            cout << str.substr(startIndex, len) << " ";
        }
    }
}
int main(){
    string str="abc";
    substrings(str);
}