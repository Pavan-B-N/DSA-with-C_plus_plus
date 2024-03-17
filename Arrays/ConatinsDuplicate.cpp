// find whether the given array contains duplicate or not
// for finding duplicates it takes o(n^2)
// so sort the array with o(nlogn) complexity and compare the adjacent elemnets so if u find both are equal return false , therefore total time complexity is o(nlogn)
#include <iostream>
#include <set> // takes logn time complexity for insertion as well as for deletion of an element
using namespace std;

// Time complexity = o(nlogn)
void contains_duplicate(int arr[], int n)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i]) != s.end())
        {
            cout << "Array contains duplicate elements";
            return;
        }
        s.insert(arr[i]);
    }
    cout << "Array does not contains any duplicate elements";
}
int main()
{   
    // int arr[]={1,2,3,1};
    int arr[]={1,2,3,3,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    contains_duplicate(arr,len);
    return 0;
}