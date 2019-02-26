## C++ sensitive words filter 
This is an sensitive words filter implemented by c++. The filter is suitable for UTF-8 encoded string. 
## Usage
### init filter
```
// init filter with vector
std::vector<string> sensitive_words;
WordsFilterTree words_filter(sensitive_words);
// add single sensitive word to filter
words_filter.addSensitiveWord(word);
```
### Match all sensitive words in text
```
// user can match type, 1 means min match, 2 means max match
words_filter.findAllSensitiveWords(text, match_type);
```
### Replace all sensitive words in text
```
// user can set match_type, whether use unix color output or replaced char
words_filter.replaceAllSensitiveWords(text)
```
## Compile
> g++ -std=c++11 test_words_filter.cpp words_filter.cpp -o words_filter

## Example
> ./words_filter

![pic](https://github.com/ce39906/self-practices/blob/master/imgs/words_filter.png)