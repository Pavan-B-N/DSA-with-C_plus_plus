// https://leetcode.com/problems/next-greater-element-ii/
#include <vector>
#include <stack>
using namespace std;


// not optimized
vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> flattenArr;
    flattenArr.reserve(nums.size() * 2); // Optional, improves performance

    // First copy
    flattenArr.insert(flattenArr.end(), nums.begin(), nums.end());
    // Second copy
    flattenArr.insert(flattenArr.end(), nums.begin(), nums.end());

    stack<int> s;//ele
    vector<int> res(flattenArr.size(),-1);

    for(int i=flattenArr.size()-1;i>=0;i--){
        while(!s.empty() && s.top()<=flattenArr[i]){
            s.pop();
        }
        if(s.empty()){
            res[i]=-1;
        }
        else{
            res[i]=s.top();
        }
        s.push(flattenArr[i]);

    }

    vector<int> finalRes(res.begin(), res.begin() + nums.size());

    return finalRes;

}

// optimized
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!s.empty() && nums[s.top()] <= nums[i % n]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i % n] = nums[s.top()];
        }
        s.push(i % n);
    }
    return ans;
}