/*************************************************************************
    > File Name: designHashMap.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-18 17:11:47
 ************************************************************************/
struct Node
{
    Node(int key, int val, bool deleted)
        : key(key), val(val), deleted(deleted)
    {
    }

    int key;
    int val;
    bool deleted;
};
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        buckets.resize(kBucketNum);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key & kBucketNum - 1;
        auto& nodes = buckets[idx];
        for (auto& node : nodes)
        {
            if (node.key == key)
            {
                node.val = value;
                node.deleted = false;
                return;
            }
        }
        
        buckets[idx].emplace_back(key, value, false);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key & kBucketNum - 1;
        const auto& nodes = buckets.at(idx);
        for (const auto& node : nodes)
        {
            if (node.key == key && !node.deleted)
            {
                return node.val;
            }
        }

        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key & kBucketNum - 1;
        auto& nodes = buckets[idx];
        for (auto& node : nodes)
        {
            if (node.key == key)
            {
                node.deleted = true;
            }
        }
    }
private:
    static const int kBucketNum = 4096;
    vector<list<Node>> buckets;
};
