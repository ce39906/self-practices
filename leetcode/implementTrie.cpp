/*************************************************************************
    > File Name: implementTrie.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-28 14:37:55
 ************************************************************************/
struct Node
{
    Node(char c) : c(c), end(false), childrens(vector<Node*>(26))
    {
    }
    
    char c;
    bool end;
    vector<Node*> childrens;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            const char c = word[i];
            Node* next = cur->childrens[c - 'a'];
            if (next)
            {
                if (i == word.size() - 1)
                {
                    next->end = true;
                }
                cur = next;
            }
            else
            {
                Node* node = new Node(c);
                if (i == word.size() - 1)
                {
                    node->end = true;
                }
                cur->childrens[c - 'a'] = node;
                cur = node;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            const char c = word[i];
            Node* children = cur->childrens[c - 'a'];
            if (!children)
            {
                return false;
            }
            
            if (i == word.size() - 1 && children->end)
            {
                return true;
            }
            
            cur = children;
        }
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for (int i = 0;  i < prefix.size(); i++)
        {
            const char c = prefix[i];
            Node* children = cur->childrens[c - 'a'];
            if (!children)
            {
                return false;
            }
            
            if (i == prefix.size() - 1)
            {
                return true;
            }
            
            cur = children;
        }
        
        return false;
    }
    
private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
