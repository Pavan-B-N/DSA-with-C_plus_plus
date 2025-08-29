// https://www.geeksforgeeks.org/problems/subset-sums2234/1&selectedLang=python3
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> res;
        findSubsetsSum(0,arr,res,0);
        return res;
    }
    void findSubsetsSum(int index, vector<int> &arr, vector<int> &res,int sum){
        if(index==arr.size()){
            res.push_back(sum);
            return;
        }
        // notPick
        findSubsetsSum(index+1,arr,res,sum);
        
        // pick
        findSubsetsSum(index+1,arr,res,sum+arr[index]);
    }
};

