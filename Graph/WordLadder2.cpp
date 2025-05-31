// https://leetcode.com/problems/word-ladder-ii/
// https://www.geeksforgeeks.org/problems/word-ladder-ii/1
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


// LeetCode Memory limit: its not working on leetcode because it requires cp to reduce memory usage
// but works in GFG
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        queue<vector<string>> q;// transformed wordList

        q.push({beginWord});

        unordered_set<string> usedOnLevel;
        usedOnLevel.insert(beginWord);

        int level=0;

        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();

            if(vec.size()>level){
                level++;
                for(string ele:usedOnLevel){
                    wordSet.erase(ele);
                }
                usedOnLevel.clear();  // removes all elements
            }   

            string word=vec.back();
            if(word==endWord){
                if(ans.empty()){
                    ans.push_back(vec);
                }else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
                else{
                    return ans;
                }
            }

            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(wordSet.count(word)){
                        usedOnLevel.insert(word);
                        vec.push_back(word);
                        q.push(vec);

                        vec.pop_back();
                    }
                }

                word[i]=original;
            }
        }

        return ans;

    }
};