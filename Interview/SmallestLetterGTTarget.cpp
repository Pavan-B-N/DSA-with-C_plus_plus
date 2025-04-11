/*
https://leetcode.com/problems/find-smallest-letter-greater-than-target/
*/
#include <vector>
using namespace std;
class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            int start=0;
            int end=letters.size()-1;
            int foundIndex=-1;
    
            while(start<=end){
                int mid=start+(end-start)/2;
                if(letters[mid]==target){
                    foundIndex=mid;
                    start=mid+1;
                }else if(letters[mid]>target){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }
    
            if(foundIndex==-1){
                return letters[(start)%letters.size()];
            }
    
            return letters[(foundIndex+1)%letters.size()];
        }
    };