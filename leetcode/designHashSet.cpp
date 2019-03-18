/*************************************************************************
    > File Name: designHashSet.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-18 16:45:12
 ************************************************************************/
struct Node
{
    Node(int key, bool deleted) : key(key), deleted(deleted)
    {
    }

    int key;
    bool deleted;
};
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        buckets.resize(kBucketNum);
    }
    
    void add(int key) {
        int idx = key & kBucketNum - 1;
        buckets[idx].emplace_back(key, false);
    }
    
    void remove(int key) {
        if (!contains(key))
        {
            return;
        }
        int idx = key & kBucketNum - 1;
        auto& nodes = buckets.at(idx);
        for (auto& node : nodes)
        {
            if (node.key == key)
            {
                node.deleted = true;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = key & kBucketNum - 1;
        const auto& nodes = buckets.at(idx);
        for (const auto& node : nodes)
        {
            if (node.key == key && !node.deleted)
            {
                return true;
            }
        }

        return false;
    }

private:
    vector<list<Node>> buckets;
    static const int kBucketNum = 2048;

};
