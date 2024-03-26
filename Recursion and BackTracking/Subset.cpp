/*
subsets of s="abc"
subsets=[a,b,c,ab,ac,bc,abc,""]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// processed and unprocessed string
void subsets(string p,string up){
    if(up==""){
        cout<<p<<" ";
        return;
    }
    //consider it
    char ch=up[0];
    subsets(p+ch,up.substr(1,up.size()));
    //ignore it
    subsets(p,up.substr(1,up.size()));
}

void subsetsIncludingAscii(string p,string up){
    if(up==""){
        cout<<p<<" ";
        return;
    }
    //consider it
    char ch=up[0];
    subsetsIncludingAscii(p+ch,up.substr(1,up.size()));

    //ignore it
    subsetsIncludingAscii(p,up.substr(1,up.size()));

    //ascii
    subsetsIncludingAscii(p+to_string((int)ch),up.substr(1,up.size()));
}

void subsetsOfArray(vector<int> p,vector<int> up,vector<vector<int>> &res){
    if(up.size()==0){
        res.push_back(p);
        return;
    }
    //consider it
    int ele=up[0];
    //ignore it
    subsetsOfArray(p,vector<int>(up.begin() + 1, up.end()),res);
    //consider it
    p.push_back(ele);
    subsetsOfArray(p,vector<int>(up.begin() + 1, up.end()),res);

}

vector<vector<int>> subsetsOfArray(vector<int> arr){
    vector<vector<int>> res;
    subsetsOfArray({},arr,res);
    return res;
}
void printVec(vector<vector<int>> vec){
    for(auto &arr:vec){
        cout<<"[ ";
        for(auto &ele:arr){
            cout<<ele<<",";
        }
        cout<<" ]";
    }
}
int main(){
    string str="abc";
    // subsets("",str);
    // subsetsIncludingAscii("",str);

    vector<int> arr={1,2,3};
    vector<vector<int>> res=subsetsOfArray(arr);
    printVec(res);
    return 0;
}