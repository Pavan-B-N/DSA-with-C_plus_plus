// https://leetcode.com/problems/first-unique-character-in-a-string/description/
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> map; // char,freq
        queue<int> queue;             // unique elements index s[i]=ele

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (map.find(ch) == map.end())
            {
                queue.push(i);
            }
            map[ch]++;
        }

        while (!queue.empty() && map[s[queue.front()]] > 1)
        {
            queue.pop();
        }
        return queue.empty() ? -1 : queue.front();
    }
};