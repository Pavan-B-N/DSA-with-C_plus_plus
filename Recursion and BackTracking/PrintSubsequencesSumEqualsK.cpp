#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<int> &arr){
    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

void printSubSequenceSumEqualsK(vector<int> &arr,int target,int index,vector<int> &subSequence){
    if(index<0){
        if(target==0 && subSequence.size()>=1){
            printArr(subSequence);
        }
        return;
    }
    //pick
    if(target>=arr[index]){
        subSequence.push_back(arr[index]);
        printSubSequenceSumEqualsK(arr,target-arr[index],index-1,subSequence);    
        subSequence.pop_back();
    }

    // notpick
    printSubSequenceSumEqualsK(arr,target,index-1,subSequence);    
}

bool printSingleSubSequenceSumEqualsK(vector<int> &arr,int target,int index,vector<int> &subSequence){
    if(index<0){
        if(target==0 && subSequence.size()>=1){
            printArr(subSequence);
            return true;
        }
        return false;
    }
    //pick
    if(target>=arr[index]){
        subSequence.push_back(arr[index]);
        if(printSingleSubSequenceSumEqualsK(arr,target-arr[index],index-1,subSequence)){
            return true;
        }
        subSequence.pop_back();
    }

    // notpick
    return printSingleSubSequenceSumEqualsK(arr,target,index-1,subSequence);    
}

int main(int argc, char const *argv[])
{
    vector<int> arr={3,1,2,4,5};
    vector<int> subSequence;
    // printSubSequenceSumEqualsK(arr,3,arr.size()-1,subSequence);
    printSingleSubSequenceSumEqualsK(arr,3,arr.size()-1,subSequence);
    
    
    return 0;
}
