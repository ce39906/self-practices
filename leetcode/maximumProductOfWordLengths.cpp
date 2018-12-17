/*************************************************************************
    > File Name: maximumProductOfWordLengths.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-17 19:07:21
 ************************************************************************/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        sort(words.begin(), words.end(), [](const string& word1, const string& word2){
            return word1.size() > word2.size();
        });
        
        const int size = words.size();
        vector<int> encoded(size, 0);
        for (int i = 0; i < size; i++)
        {
            const string& word = words[i];
            for (const auto c : word)
            {
                encoded[i] |= 1 << c - 'a';
            }
        }
        
        for (int i = 0; i < size; i++)
        {
            const int i_size = words[i].size();
            if (i_size * i_size < res)
            {
                break;
            }
            
            for (int j = i + 1; j < size; j++)
            {
                const int j_size = words[j].size();
                const int product = i_size * j_size;
                if (product < res)
                {
                    break;
                }
                
                if (!(encoded[i] & encoded[j]))
                {
                    res = max(res, product);
                }
            }
        }
        
        return res;
    }

};
