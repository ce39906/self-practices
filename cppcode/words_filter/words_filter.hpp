/*************************************************************************
    > File Name: words_filter.hpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-25 15:05:00
 ************************************************************************/
#ifndef WORDS_FILTER_HPP
#define WORDS_FILTER_HPP
#include <map>
#include <vector>
#include <set>
#include <string>

struct TreeNode
{
    using TreeMap = std::map<unsigned char, TreeNode*>;
    
    TreeNode()
    {
        c_ = '0';
        is_end_ = false;
    }

    TreeNode(unsigned char c, bool is_end) :
        c_(c), is_end_(is_end)
    {
    }

    TreeNode* findChild(const unsigned char next_char) const
    {
        if (subtree_map_.count(next_char))
        {
            return subtree_map_.at(next_char);
        }

        return nullptr;
    }
    // insert and return child node
    TreeNode* insertChild(const unsigned char next_char)
    {
        // already have the child
        if (findChild(next_char))
        {
            return nullptr;
        }

        TreeNode* child = new TreeNode(next_char, false);
        if (child == nullptr)
        {
            return nullptr;
        }

        subtree_map_.insert(std::make_pair(next_char, child));
        return child;
    }
    // keyword
    unsigned char c_;
    // end flag
    bool is_end_;
    // subtree
    TreeMap subtree_map_;
};

class WordsFilterTree
{
  public:
    WordsFilterTree(const std::vector<std::string>& sensitive_words);
    
    bool addSensitiveWord(const std::string& sensitive_word);
    
    std::set<std::string> findAllSensitiveWords(const std::string& text,
                                                const int match_type = 2) const;

    std::string replaceAllSensitiveWords(const std::string& text,
                                         const bool unix_shell_colored = true,
                                         const int match_type = 2,
                                         const unsigned char replaced_char = '*') const;
    
  private:
    TreeNode root_;

    bool insert(TreeNode* parent, const std::string& sensitive_word);

    int checkSensitiveWord(const TreeNode* node,
                           const std::string& text,
                           const int begin_index,
                           const int match_type) const;
};

static const int kMinMatch = 1;
static const int kMaxMatch = 2;
static const int kBoldRedANSIColorCodeLen = 11;
static const std::string kBoldRedANSIColorCodePrefix = "\033[1;31m";
static const std::string kBoldRedANSIColorCodeSuffix = "\033[0m";

static int utf8StringLen(const std::string& word)
{
    const char* s = word.c_str();
    int len = 0;
    while (*s) len += (*s++ & 0xc0) != 0x80;
    return len;
}

#endif
