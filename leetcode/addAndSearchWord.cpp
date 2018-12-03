/*************************************************************************
    > File Name: addAndSearchWord.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-03 19:26:47
 ************************************************************************/
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        const int size = word.size();
        if (size_2_words.count(size))
        {
            size_2_words[size].push_back(word);
        }
        else
        {
            size_2_words[size] = vector<string>(1, word);
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        const int size = word.size();
        if (!size_2_words.count(size))
        {
            return false;
        }
        
        const vector<string>& words = size_2_words[size];
        for (const string& candidate : words)
        {
            int i = 0;
            for (; i < size; i++)
            {
                const char cand_char = candidate[i];
                const char word_char = word[i];
                if (  cand_char == word_char
                   || cand_char == '.'
                   || word_char == '.')
                {
                    continue;
                }
                
                if (cand_char != word_char)
                {
                    break;
                }
            }
            
            if (i == size)
            {
                return true;
            }
        }
        
        return false;
    }
    
private:
    unordered_map<int, vector<string>> size_2_words;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
