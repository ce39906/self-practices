/*************************************************************************
    > File Name: repeatedDNASequences.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 14:25:50
 ************************************************************************/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10)
        {
            return res;
        }
        
        unordered_set<string> sequence_set;
        unordered_set<string> m;
        for (int i = 0; i <= s.size() - 10; i++)
        {
            const string sequence = s.substr(i, 10);
            if (m.count(sequence))
            {
                sequence_set.insert(std::move(sequence));
            }
            else
            {
                m.insert(sequence);
            }
        }
        
        return vector<string>(sequence_set.begin(), sequence_set.end());
    }
};
