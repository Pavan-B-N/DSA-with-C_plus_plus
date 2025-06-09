// https://leetcode.com/problems/valid-anagram/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// optimal
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> freq(26, 0); // initialize all 26 positions to 0

    for (char ch : s) {
        freq[ch - 'a']++;
    }

    for (char ch : t) {
        freq[ch - 'a']--;
        if (freq[ch - 'a'] < 0) return false; // optimization: early exit
    }

    // no need to loop again, since we already checked for negatives above
    return true;
}


bool isAnagram(string s, string t) {
    if(s.size()!=t.size()){
        return false;
    }
    unordered_map<char,int> map;//char , frq
    for(char ch:s){
        map[ch]++;
    }

    for(char ch:t){
        if(map.find(ch)==map.end() || map[ch]<=0){
            return false;
        }
        map[ch]--;
    }

    for(auto pair:map){
        if(pair.second!=0){
            return false;
        }
    }

    return true;
}