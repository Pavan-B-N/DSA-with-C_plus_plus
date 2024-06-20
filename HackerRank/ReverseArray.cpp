// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    
    return 0;
}

vector<int> reverseArray(vector<int> a) {
    int i=0;
    int j=a.size()-1;
    while(i<j){
        swap(a[i],a[j]);
        i++;
        j--;
    }
    
    return a;
}
