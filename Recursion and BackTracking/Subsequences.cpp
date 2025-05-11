#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<int> &arr){
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}
void printSubSequences(vector<int> &arr,int n,int index,vector<int> &subSequence){
    if(index==n){
        printArr(subSequence);
        return;
    }

    //pick
    subSequence.push_back(arr[index]);
    printSubSequences(arr,n,index+1,subSequence); 
    // not pick
    subSequence.pop_back();
    printSubSequences(arr,n,index+1,subSequence);

}
int main(int argc, char const *argv[])
{
    vector<int> arr={1,2,3};
    vector<int> subSequence;
    printSubSequences(arr,arr.size(),0,subSequence);
    return 0;
}
