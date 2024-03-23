#include <iostream>
#include <vector>
using namespace std;
// A substring is a contiguous sequence of characters within a string
void substrings(string str){
    int length = str.length();

    for (int startIndex = 0; startIndex < length; startIndex++) {
        for (int len = 1; len <= length - startIndex; len++) {
            cout << str.substr(startIndex, len) << " ";
        }
    }
}

void subsetsHelper(string p,string up,vector<string> &res){
    if(up==""){
        res.push_back(p);
        return;
    }
    //condiser
    subsetsHelper(p+up[0],up.substr(1),res);
    subsetsHelper(p,up.substr(1),res);
}
// A subset is a collection of elements that are part of a larger set.
// Note: in case of subsets order doesn't change but in permutation we can also change the order
vector<string> subsets(string str){
    vector<string> res;
    subsetsHelper("",str,res);
    return res;
}

int main(){
    string str="abc";
    // substrings(str);
    vector<string> res=subsets(str);
    for(auto &ele:res){
        if(ele==""){
            cout<<"null"<<" ";
            continue;
        }
        cout<<ele<<" ";
    }
    return 0;
}