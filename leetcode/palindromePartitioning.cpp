/*************************************************************************
    > File Name: palindromePartitioning.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2018-11-05 08:16:28
 ************************************************************************/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, res, path, 0);
        return res;
    }
private:
    void dfs(const string& s,
             vector<vector<string>>& res,
             vector<string>& path,
             int start) const
    {
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }
        
        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, res, path, i + 1);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s,
                      int start,
                      int end) const
    {
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
};
