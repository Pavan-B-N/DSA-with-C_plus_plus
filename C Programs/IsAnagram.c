// Write a program in C to check if two strings are Anagram
/*
Two Strings are said to be anagram if both contains a same characters, but in a different order.
For example, "abcd" and "dabc" are anagrams of each other, but daabc is not a anagram
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_anagram(char *str1,char *str2);

int main(){
    char *str1="abcd";
    char *str2="bcad";
    bool res=is_anagram(str1,str2);
    if(res){
        printf("Given Strings are anagram");
    }else{
        printf("Given Strings are not anagram");
    }
    return 0;
}
bool is_anagram(char *str1,char *str2){
    // count character frequencies 
    int charCount[256]={0};// Assuming Acii Characters
    
    int len1=strlen(str1);
    int len2=strlen(str2);

    //if length of the two strings are not equal then its not a anagram
    if(len1!=len2){
        return false;
    }   
    // increment and decrement frequency count, so at the last they should be zero
    for(int i=0;i<len1;i++){
        charCount[str1[i]]++;
        charCount[str2[i]]--;
    }
    // If the strings are anagrams, all character counts should be 0
    for(int i=0;i<256;i++){
        if(charCount[i]!=0){
            return false;
        }
    }
    return true;
}