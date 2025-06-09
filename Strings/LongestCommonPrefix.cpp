// https://leetcode.com/problems/longest-common-prefix/description/

#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// O(N∗M∗Log(M))
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()<=0){
        return "";
    }
    if(strs.size()==1){
        return strs[0];
    }
    sort(strs.begin(),strs.end());
    // once we sort, strings are arranged in lexicographical manner
    // so only first and last string is required

    string res="";
    string first=strs[0];
    string last=strs[strs.size()-1];


    for(int i=0;i<first.length();i++){
        if(first[i]!=last[i]){
            break;
        }
        res+=first[i];
    }

    return res;
}