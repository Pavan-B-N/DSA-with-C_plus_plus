// https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21
/*
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
*/
#include <vector>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    // first find the customers satisfied when shopowner is not grumpy
    int satisfied=0;
    int n=customers.size();
    for(int i=0;i<n;i++){
        if(grumpy[i]!=1){
            satisfied+=customers[i];
            customers[i]=0;
        }
    }

    // now, shopowner can be cool or will not get grumpy for x(minutes) consqcutively
    // so we can use window of size minutes
    int maxCustomerInWindow=0;
    for(int i=0;i<(n-minutes+1);i++){
        int sum=0;
        for(int j=i;j<(i+minutes);j++){
            sum+=customers[j];
        }
        if(sum>maxCustomerInWindow){
            maxCustomerInWindow=sum;
        }
    }

    // now add maxCustomerInWindow which shopowner will not be grumpy to the satisfied customer list
    satisfied+=maxCustomerInWindow;
    return satisfied;
}