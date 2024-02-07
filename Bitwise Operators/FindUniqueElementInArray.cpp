// find the unique elemenet in an array
// note : elements are repeated even number of times

#include <iostream>
#include <map>
using namespace std;
// even number of times repetation
// since the duplicates are repeated even number of times so we can utilize the
// xor operator
// xor set for 1st operation and will be reset for 2nd opeartion
// so the element which is unique it will be set and remained
// o(n)
int uniqueElement(int arr[], int n)
{
    int unique = 0;
    for (int i = 0; i < n; i++)
    {
        unique = unique ^ arr[i];
    }
    return unique;
}

// o(n) -> using hashmap
void findUnique(int arr[],int n){
    map<int,int> hashmap;
    // add and count elements
    for(int i=0;i<n;i++){
        if(hashmap.count(arr[i])>0){
            hashmap[arr[i]]++;
        }else{
            hashmap[arr[i]]=1;
        }
    }

    int unique=-1;
    //print
    for(const auto &pair:hashmap){
        cout<<pair.first<<" : "<<pair.second<<endl;
        if(pair.second==1){
            unique=pair.first;
        }
    }

    //print unique element
    cout<<"Hence Element "<<unique<<" is unique in the array";
}
int main()
{
    int arr[] = {2, 3, 4, 4, 4, 1, 2, 1, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int res = uniqueElement(arr, n);
    findUnique(arr,n);
    // cout << res << endl;
}