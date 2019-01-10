/*************************************************************************
    > File Name: LFUCache.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-10 11:27:52
 ************************************************************************/
struct Node
{
    int key;
    int val;
    int freq;
    list<int>::iterator it;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
        min_freq_ = 0;
    }
    
    int get(int key) {
        if (capacity_ <= 0)
        {
            return -1;
        }
        
        if (m_.count(key))
        {
            Node node = m_[key];
            touch(node);
            m_[key] = node;
            return node.val;
        }
       
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity_ <= 0)
        {
            return;
        }
        // update
        if (m_.count(key))
        {
            Node& node = m_[key];
            touch(node);
            node.val = value;
            return;
        }
         // evict key
        if (capacity_ == m_.size())
        {
            const int key_to_evict = l_[min_freq_].back();
            l_[min_freq_].pop_back();
            m_.erase(key_to_evict);
        }
        
        const int freq = 1;
        min_freq_ = freq;
        l_[freq].push_front(key);
        m_[key] = {key, value, freq, l_[freq].begin()};
    }
private:
    
    void touch(Node& node)
    {
        int freq = node.freq;
        l_[freq].erase(node.it);
        node.freq++;
        if (l_[freq].empty() && freq == min_freq_)
        {
            l_.erase(freq);
            min_freq_++;
        }
        l_[freq + 1].push_front(node.key);
        node.it = l_[freq + 1].begin();
    }
    int capacity_;
    int min_freq_;
    unordered_map<int, list<int>> l_;
    unordered_map<int, Node> m_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

struct Node
{
    int key;
    int val;
    int freq;
    long tick;

    bool operator < (const Node& rhs) const
    {
        if (freq < rhs.freq)
        {
            return true;
        }

        if (freq == rhs.freq)
        {
            return tick < rhs.tick;
        }

        return false;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
        tick_ = 0;
    }

    int get(int key) {

        if (m_.count(key))
        {
            Node& node = m_[key];
            const int val = node.val;
            touch(node);
            return val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (capacity_ <= 0)
        {
            return;
        }

        // update
        if (m_.count(key))
        {
            Node& node = m_[key];
            node.val = value;
            touch(node);
            return;
        }
        // evict
        if (capacity_ == m_.size())
        {
            const Node& node = *(s_.cbegin());
            const int key_to_evict = node.key;
            m_.erase(key_to_evict);
            s_.erase(node);
        }

        Node node = {key, value, 1, ++tick_};
        m_[key] = node;
        s_.insert(node);
    }
private:

    void touch(Node& node)
    {
        s_.erase(node);
        node.freq++;
        node.tick = ++tick_;
        s_.insert(node);
    }

    long tick_;
    int capacity_;
    unordered_map<int, Node> m_;
    set<Node> s_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
