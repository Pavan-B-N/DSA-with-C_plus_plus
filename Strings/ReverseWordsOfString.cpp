// https://leetcode.com/problems/reverse-words-in-a-string/description/
#include <iostream>
using namespace std;

string reverseWords(string s) {
    int n=s.length();
    string ans="";

    reverse(s.begin(),s.end());
    
    for(int i=0;i<n;i++){
        string word="";
        while(i<n && s[i]!=' '){
            word+=s[i];
            i++;
        }
        
        if(word.length()>0){
            reverse(word.begin(),word.end());
            ans+=' '+word;
        }
    }

    return ans.substr(1);
}