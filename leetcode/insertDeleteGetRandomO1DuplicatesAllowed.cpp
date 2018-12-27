/*************************************************************************
    > File Name: insertDeleteGetRandomO1DuplicatesAllowed.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-27 19:10:24
 ************************************************************************/
struct Node
{
    Node(int val) : val(val), deleted(false)
    {
    }
    int val;
    bool deleted;
};

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = true;
        const int idx = nodes.size();
        nodes.emplace_back(val);
        if (val_2_counts.count(val))
        {
            res = false;
            val_2_idxs[val].push_back(idx);
        }
        else
        {
            vector<int> idxs;
            idxs.push_back(idx);
            val_2_idxs[val] = idxs;
        }
        
        val_2_counts[val]++;
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool res = false;
        if (val_2_counts.count(val))
        {
            res = true;
            if (val_2_counts[val] > 1)
            {
                val_2_counts[val]--;
            }
            else
            {
                val_2_counts.erase(val);
            }
            int idx = val_2_idxs[val].back();
            nodes[idx].deleted = true;
            val_2_idxs[val].pop_back();
        }
        
        return res;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        const int size = nodes.size();
        while (true)
        {
            int rand_idx = rand() % size;
            if (!nodes[rand_idx].deleted)
            {
                return nodes[rand_idx].val;
            }
        }
        
        return -1;
    }
private:
    unordered_map<int, int> val_2_counts;
    vector<Node> nodes;
    unordered_map<int, vector<int>> val_2_idxs;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
