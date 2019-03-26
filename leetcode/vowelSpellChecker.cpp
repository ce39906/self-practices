/*************************************************************************
    > File Name: vowelSpellChecker.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-21 16:48:34
 ************************************************************************/
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (string str : wordlist)
        {
            ori_dict.insert(str);
            string low = tolow(str);
            string devow = tovow(str);
            low_dict.insert({low, str});
            vow_dict.insert({devow, str});
        }

        for (int i = 0; i < queries.size(); i++)
        {
            if (ori_dict.count(queries[i]))
            {
                continue;
            }

            string low = tolow(queries[i]);
            string devow = tovow(queries[i]);
            if (low_dict.count(low))
            {
                queries[i] = low_dict[low];
            }
            else if (vow_dict.count(devow))
            {
                queries[i] = vow_dict[devow];
            }
            else
            {
                queries[i] = "";
            }
        }

        return queries;
    }

private:
    string tolow(string str)
    {
        for (auto& c : str)
        {
            c = tolower(c);
        }

        return str;
    }

    string tovow(string str)
    {
        str = tolow(str);
        for (auto& c : str)
        {
            if (   c == 'a'
                || c == 'e'
                || c == 'i'
                || c == 'o'
                || c == 'u')
            {
                c = '#';
            }
        }
        return str;
    }

    unordered_map<string, string> low_dict;
    unordered_map<string, string> vow_dict;
    unordered_set<string> ori_dict;
};
