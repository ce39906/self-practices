/*************************************************************************
    > File Name: trie.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-07-19 14:04:15
 ************************************************************************/
#include "trie.hpp"
#include <iostream>

namespace trie
{

void Trie::Init(const std::vector<std::string>& dict)
{
    for (const std::string& word : dict)
    {
        Insert(word);
    }
}

bool Trie::Lookup(const std::string& word) const
{
    return Search(root, word, 0);
}

std::vector<std::string> Trie::Suggest(const std::string& word) const
{
    std::vector<std::string> suggs;
    if (word.empty())
    {
        return suggs;
    }
    // find prefix
    TrieNode* cur = root;
    // unsigned char range : 0 ~ 255
    for (const unsigned char c : word)
    {
        const std::vector<TrieNode*>& childrens = cur->childrens;
        if (!childrens[c])
        {
            return suggs;
        }
        cur = childrens[c];
    }

    if (!cur)
    {
        return suggs;
    }

    std::string prefix(word.begin(), word.end() - 1);
    Dfs(cur, prefix, suggs);
    return suggs;
}

void Trie::Insert(const std::string& word)
{
    if (word.empty())
        return;
    
    TrieNode* cur = root;
    // unsigned char range : 0 ~ 255
    for (const unsigned char c : word)
    {
        if (!cur->childrens[c])
        {
            cur->childrens[c] = new TrieNode(c);
        }
        cur = cur->childrens[c];
    }
    cur->is_end = true;
}
    
bool Trie::Search(const TrieNode* parent, const std::string& word, const size_t idx) const 
{
    if (word.empty())
    {
        return false;
    }   
    const std::vector<TrieNode*>& childrens = parent->childrens;
    // explicitly cast to unsigned char is needed
    const unsigned char c = word[idx];
    TrieNode* cur = childrens[c];
    if (!cur)
    {
        return false;
    }
    if (idx == word.size() - 1)
    {
        return cur->is_end;
    }
    return Search(cur, word, idx + 1);
}

void Trie::Dfs(const TrieNode* cur, std::string& word, std::vector<std::string>& suggs) const
{
    if (cur->is_end)
    {
        suggs.emplace_back(word + cur->val);
    }
    word.push_back(cur->val);
    const std::vector<TrieNode*>& childrens = cur->childrens;
    for (const TrieNode* children : childrens)
    {
        if (children)
        {
            Dfs(children, word, suggs);
        }
    }
    word.pop_back(); 
}

void Trie::ReleaseTrie(const TrieNode* root)
{
    if (!root) return;
    bool no_children = true;
    const std::vector<TrieNode*>& childrens = root->childrens;
    for (const TrieNode* children : childrens)
    {
        if (children)
        {
            no_children = false;
            ReleaseTrie(children);
        }
    }

    if (no_children)
    {
        delete root;
    }
}

void Trie::PrintSuggs(const std::string& word) const
{
    const auto quoted_string = [] (const std::string& str)
    {
        return "\"" + str + "\"";
    };

    const std::vector<std::string>& suggs = Suggest(word);
    if (suggs.empty())
    {
        std::cout << "No suggs for " << quoted_string(word) << std::endl;
        return;
    }

    std::cout << "Suggs for " << quoted_string(word) << " are :\n";
    for (const std::string& sugg : suggs)
    {
        std::cout << quoted_string(sugg) << " ";
    }
    std::cout << std::endl;
}

} // ns trie
