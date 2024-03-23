#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
// subset or subsequnce
vector<string> subsets(string str){
    vector<string> res;
    subsetsHelper("",str,res);
    return res;
}


void subsetsWithAsciiHelper(string p,string up,vector<string> &res){
    if(up==""){
        res.push_back(p);
        return;
    }
    //condiser
    subsetsWithAsciiHelper(p+up[0],up.substr(1),res);
    subsetsWithAsciiHelper(p+to_string((int)up[0]),up.substr(1),res);
    subsetsWithAsciiHelper(p,up.substr(1),res);
}
// A subset is a collection of elements that are part of a larger set.
// Note: in case of subsets order doesn't change but in permutation we can also change the order
// subset or subsequnce
vector<string> subsetsWithAscii(string str){
    vector<string> res;
    subsetsWithAsciiHelper("",str,res);
    return res;
}

int main(){
    string str="ab";
    // vector<string> res=subsets(str);
    vector<string> res=subsetsWithAscii(str);
    for(auto &ele:res){
        if(ele==""){
            cout<<"null"<<" ";
            continue;
        }
        cout<<ele<<" ";
    }
    return 0;
}