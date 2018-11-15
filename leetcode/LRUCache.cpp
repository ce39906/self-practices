/*************************************************************************
    > File Name: LRUCache.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-13 16:14:32
 ************************************************************************/
struct DoubleLinkedListNode 
{
    DoubleLinkedListNode(int key, int val)
        : key(key), val(val), prev(NULL), next(NULL)
    {       
    }
    
    int key;
    int val;
    DoubleLinkedListNode* prev;
    DoubleLinkedListNode* next;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        size_ = 0;
        // init double linked list
        head_ = new DoubleLinkedListNode(0, 0);
        tail_ = new DoubleLinkedListNode(0, 0);
        head_->next = tail_;
        head_->prev = NULL;
        tail_->prev = head_;
        tail_->next = NULL;
    }
    
    int get(int key) {
        if (!cache_.count(key))
        {
            return -1;
        }
        
        DoubleLinkedListNode* node = cache_[key];
        detach(node);
        attach(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache_.count(key))
        {
            DoubleLinkedListNode* node = cache_[key];
            node->val = value;
            detach(node);
            attach(node);
            return;
        }
        
        DoubleLinkedListNode* node = new DoubleLinkedListNode(key, value);
        if (size_ == capacity_)
        {
            cache_.erase(tail_->prev->key);
            detach(tail_->prev);
            cache_[key] = node;
            attach(node);
        }
        else
        {
            cache_[key] = node;
            attach(node);
            ++size_;
        }

    }
private:
    void attach(DoubleLinkedListNode* node)
    {
        node->prev = head_;
        node->next = head_->next;
        node->prev->next = node;
        node->next->prev = node;
    }
    
    void detach(DoubleLinkedListNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int capacity_;
    int size_;
    unordered_map<int, DoubleLinkedListNode*> cache_;
    DoubleLinkedListNode* head_;
    DoubleLinkedListNode* tail_;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
