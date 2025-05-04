#include <iostream>
#include <vector>
using namespace std;

// this is same we used for finding subsets, but its maintains the order
// so ordered subset == subsequence
void subSequences(string p,string up){
    if(up==""){
        cout<<p<<endl;
        return;
    }
    subSequences(p+up[0],up.substr(1));
    subSequences(p,up.substr(1));
}


int main(){
    string str="GEEKSFORGEEKS";
    subSequences("",str);
    return 0;
}