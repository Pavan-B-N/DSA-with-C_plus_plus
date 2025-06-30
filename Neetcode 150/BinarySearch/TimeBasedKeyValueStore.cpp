// https://leetcode.com/problems/time-based-key-value-store/

#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (!mp.count(key))
            return "";
        auto &vec = mp[key];
        int start = 0, end = vec.size() - 1;
        string result = "";

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (vec[mid].first == timestamp)
            {
                return vec[mid].second;
            }
            else if (vec[mid].first < timestamp)
            {
                result = vec[mid].second; // possible answer
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return result;
    }
};
