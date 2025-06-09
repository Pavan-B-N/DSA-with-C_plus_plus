#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// using sorted map
string getfrequencyStringViaMap(string str){
    map<char,int> map;// char, freq
    for(char ch:str){
        map[ch]++;
    }
    string freqStr;
    for(auto pair:map){
        freqStr+=pair.first;
        // store all digits in continuos manner
        for(char ch:to_string(pair.second)){
            freqStr+=ch;
        }
    }
    return freqStr;
}

// using regular array
string getfrequencyStringViaArr(string str){
    vector<int> arr(26,0);
    for(char ch:str){
        arr[ch-'a']++;
    }
    string freqStr;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            freqStr+=i+'a';
             // store all digits in continuos manner
            for(char ch:to_string(arr[i])){
                freqStr+=ch;
            }
        }
    }
    return freqStr;
}
int main(int argc, char const *argv[])
{

    // a4b3c1
    string str="caabacaaaaaaaaaaaaaaaaaaaaaaaaaabab";
    cout<<getfrequencyStringViaMap(str)<<endl;
    cout<<getfrequencyStringViaArr(str)<<endl;
    return 0;
}
