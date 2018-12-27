/*************************************************************************
    > File Name: insertDeleteGetRandomO1.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-27 17:57:25
 ************************************************************************/
struct Node
{
    Node(int val) : val(val), deleted(false)
    {
    }
    
    int val;
    bool deleted;
};

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (vals.count(val))
        {
            return false;
        }
        vals.insert(val);
        nodes.emplace_back(val);
        val_2_node_idx[val] = nodes.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!vals.count(val))
        {
            return false;
        }
        vals.erase(val);
        size_t idx = val_2_node_idx[val];
        nodes[idx].deleted = true;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        const int size = nodes.size();
        int idx = rand() % size;
        while (nodes[idx].deleted)
        {
            idx = rand() % size;
        }
        return nodes[idx].val;
    }
private:
    unordered_set<int> vals;
    vector<Node> nodes;
    unordered_map<int, size_t> val_2_node_idx;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
