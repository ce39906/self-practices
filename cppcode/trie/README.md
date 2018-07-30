## C++ trie implement
This trie implement can be used for any language(English, Chinese, Japanese...).
### Interface
```
// Use a set of words to initialize the trie tree.
void Init(const std::vector<std::string>& dict);
// Check whether the word is in the trie tree.
bool Lookup(const std::string& word);
// Suggest all the words whose's prefix is "word".
std::vector<std::string> Suggest(const std::string& word);
```
### Compile
```
g++ --std=c++11 -O2 trie.cpp test_trie.cpp -o trie
```
### Execute result
![pic](https://github.com/ce39906/practices/blob/master/imgs/trie.jpg)
