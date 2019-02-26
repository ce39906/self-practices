/*************************************************************************
    > File Name: words_filter.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-26 14:17:18
 ************************************************************************/
#include "words_filter.hpp"

WordsFilterTree::WordsFilterTree(const std::vector<std::string>& sensitive_words)
{
    for (const std::string& sensitive_word : sensitive_words)
    {
        insert(&root_, sensitive_word);
    }
}

bool WordsFilterTree::addSensitiveWord(const std::string& sensitive_word)
{
    return insert(&root_, sensitive_word);
}

std::set<std::string>
WordsFilterTree::findAllSensitiveWords(const std::string& text,
                                       const int match_type) const
{
    std::set<std::string> matched_words;
    int begin_index = 0;
    const int n = text.size();
    while (begin_index < n)
    {
        int match_len = checkSensitiveWord(&root_, text, begin_index, match_type);
        if (match_len == 0)
        {
            begin_index++;
        }
        else
        {
            matched_words.insert(text.substr(begin_index, match_len));
            begin_index += match_len;
        }
    }

    return matched_words;
}

std::string
WordsFilterTree::replaceAllSensitiveWords(const std::string& text,
                                          const bool unix_shell_colored,
                                          const int match_type,
                                          const unsigned char replaced_char) const
{
    //get one copy
    std::string replaced_text = text;
    int begin_index = 0;
    int shift_len = 0;
    const int n = text.size();
    while (begin_index < n)
    {
        int match_len = checkSensitiveWord(&root_, text, begin_index, match_type);
        if (match_len == 0)
        {
            begin_index++;
        }
        else
        {
            const std::string matched_word = text.substr(begin_index, match_len);
            int utf8Len = utf8StringLen(matched_word);
            std::string replaced_str = std::string(utf8Len, replaced_char);
            if (unix_shell_colored)
            {
                replaced_str =   kBoldRedANSIColorCodePrefix 
                               + replaced_str
                               + kBoldRedANSIColorCodeSuffix;
            }

            replaced_text =   replaced_text.substr(0, begin_index - shift_len)
                            + replaced_str
                            + replaced_text.substr(begin_index + match_len - shift_len);
            
            begin_index += match_len;
            shift_len += match_len - utf8Len;
            shift_len -= unix_shell_colored ? kBoldRedANSIColorCodeLen : 0;
        }
    }

    return replaced_text;
}

bool WordsFilterTree::insert(TreeNode* parent, const std::string& sensitive_word)
{
    
    const int n = sensitive_word.size();
    for (int i = 0; i < n; i++)
    {
        if (!parent)
        {
            return false;
        }
        
        const unsigned char c = sensitive_word[i];
        TreeNode* child = parent->findChild(c);
        if (!child)
        {
            parent = parent->insertChild(c);
        }
        else
        {
            parent = child;
        }

        if (i == n - 1)
        {
            parent->is_end_ = true;
        }
    }

    return true;
}

int WordsFilterTree::checkSensitiveWord(const TreeNode* node,
                                        const std::string& text,
                                        const int begin_index,
                                        const int match_type) const
{
    bool flag = false;
    int match_len = 0;
    const int n = text.size();
    for (int i = begin_index; i < n; i++)
    {
        const unsigned char c = text[i];
        node = node->findChild(c);
        if (!node)
        {
            break;
        }
        else
        {
            match_len++;
            if (node->is_end_)
            {
                flag = true;
                if (match_type == kMinMatch)
                {
                    break;
                }
            }
        }
    }

    if (match_len < 2 || !flag)
    {
        match_len = 0;
    }

    return match_len;
}
