/*************************************************************************
    > File Name: timeBasedKeyValueStore.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-14 14:12:25
 ************************************************************************/
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (storage.count(key))
        {
            storage[key][timestamp] = value;
        }
        else
        {
            map<int, string> timestamp_2_value;
            timestamp_2_value[timestamp] = value;
            storage[key] = timestamp_2_value;
        }
    }
    
    string get(string key, int timestamp) {
        if (!storage.count(key))
        {
            return "";
        }
        
        const map<int, string>& timestamp_2_value = storage.at(key);
        if (timestamp_2_value.empty())
        {
            return "";
        }

        auto lit = timestamp_2_value.lower_bound(timestamp);
        if (lit == timestamp_2_value.end())
        {
            return timestamp_2_value.rbegin()->second;
        }

        if (lit->first == timestamp)
        {
            return lit->second;
        }

        if (lit == timestamp_2_value.begin())
        {
            return "";
        }
        
        --lit;
        return lit->second;
    }
private:
    unordered_map<string, map<int, string>> storage;
};
