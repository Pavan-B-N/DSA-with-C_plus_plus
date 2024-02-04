#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    // string str="hello";
    string str="mom";
    string reverseStr=str;
    int start=0;
    int end=reverseStr.length()-1;
    //reverse the string
    while(start<end){
        swap(reverseStr[start],reverseStr[end]);
        start++;
        end--;
    }

    if(str==reverseStr){
        cout<<"Palindrome string";
    }else{
        cout<<"Not a Palindrome string";
    }

}