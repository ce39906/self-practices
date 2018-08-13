/*************************************************************************
    > File Name: letterCombinations.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-13 19:39:55
 ************************************************************************/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        const vector<string> dict = 
            {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string path;
        dfs(digits, dict, path, 0, res);
        return res;
    }
private:
    void dfs(const string& digits,
             const vector<string>& dict,
             string& path,
             size_t cur,
             vector<string>& res)
    {
        if (cur == digits.size())
        {
            res.push_back(path);
            return;
        }
        const string& vals = dict.at(digits[cur] - '0' - 2);
        for (const char c : vals)
        {
            path.push_back(c);
            dfs(digits, dict, path, cur + 1, res);
            path.pop_back();
        }
    }
};
