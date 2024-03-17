/*
Input: 100
Output: 933262154439441526816992388562667004-
         907159682643816214685929638952175999-
         932299156089414639761565182862536979-
         208272237582511852109168640000000000-
         00000000000000



we can store the elements of an factorial in the continuos manner using array
*/
#include <iostream>
#include <vector>
using namespace std;
void multiply(vector<int> &arr,int &size,int multiplier){
    int carry=0;
    for(int i=0;i<size;i++){
        int res=arr[i]*multiplier;
        res+=carry;
        arr[i]=res%10;
        carry=res/10;
    }

    while(carry>0){
        arr[size]=carry%10;
        size++;
        carry/=10;
    }
}

vector<int> factorial(int n){
    vector<int> arr(100,0);
    arr[0]=1;
    int size=1;
    for(int multiplier=2;multiplier<=n;multiplier++){
        multiply(arr,size,multiplier);
    }
    vector<int> res;
    for(int i=size-1;i>=0;i--){
        res.push_back(arr[i]);
    }
    return res;
}

int main(){
    vector<int> res=factorial(5);
    for(auto &ele:res){
        cout<<ele;
    }
    return 0;
}