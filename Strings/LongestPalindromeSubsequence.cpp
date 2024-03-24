// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
/*
Longest Palindromic Subsequence (LPS)

The Longest Palindromic Subsequence (LPS) is the problem of finding a maximum-length subsequence of a given string that is also a Palindrome.
*/
// it is an dynamic programming problem so normal solution will be given in this code
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string str){
    int i=0;
    int j=str.length()-1;
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// only palindromic subsequences
void subSequences(string p,string up,vector<string> &res){
    if(up==""){
        if(p!="" && isPalindrome(p)){
            // add only palindrome subset
            res.push_back(p);
        }
        return;
    }
    subSequences(p+up[0],up.substr(1),res);
    subSequences(p,up.substr(1),res);
}

string longestPalindromeSubSequnece(string str){
    vector<string> palindromicSubSequences;
    subSequences("",str,palindromicSubSequences);

    string longestPalindrome="";
    for(auto &ele:palindromicSubSequences){
        if(longestPalindrome.length()<ele.length()){
            longestPalindrome=ele;
        }
        // cout<<ele<<endl;
    }
    return longestPalindrome;
}

int main(){
    string str="GEEKSFORGEEKS";
    cout<<longestPalindromeSubSequnece(str);
    return 0;
}