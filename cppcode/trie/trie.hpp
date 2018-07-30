/*************************************************************************
    > File Name: trie.hpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-07-19 11:12:09
 ************************************************************************/
#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>

namespace trie
{

class Trie
{
    static constexpr size_t kAsciiCount = 256;
    struct TrieNode
    {
        TrieNode(const char val)
          : val(val), is_end(false), childrens(kAsciiCount, nullptr)
        {
        }

        char val;
        bool is_end;
        std::vector<TrieNode*> childrens;
    };

  public:
    Trie()
    {
        root = new TrieNode('0');
    }

    ~Trie()
    {
        ReleaseTrie(root);
    }

    Trie(const Trie&) = delete;
    Trie& operator = (const Trie&) = delete;

    void Init(const std::vector<std::string>& dict);

    bool Lookup(const std::string& word) const;

    std::vector<std::string> Suggest(const std::string& word) const;
    
    void PrintSuggs(const std::string& word) const;

  private:
    
    void Insert(const std::string& word);
    
    bool Search(const TrieNode* parent, const std::string& word, const size_t idx) const; 
    
    void Dfs(const TrieNode* cur, std::string& word, std::vector<std::string>& suggs) const;

    void ReleaseTrie(const TrieNode* root);

    TrieNode* root;
};
} // ns trie
#endif


