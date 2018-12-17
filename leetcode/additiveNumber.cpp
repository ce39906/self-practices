/*************************************************************************
    > File Name: additiveNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-17 16:35:06
 ************************************************************************/
class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<string> paths;
        bool res = false;
        dfs(num, 0, paths, res);
        return res;
    }
private:
    void dfs(const string& num,
             int cur,
             vector<string>& paths,
             bool& res) const
    {
        if (res)
        {
            return;
        }
        
        if (paths.size() >= 3 && !isValidPaths(paths))
        {
            return;
        }
        
        if (cur == num.size())
        {
            if (paths.size() >= 3 && isValidPaths(paths))
            {
                res = true;
            }
            return;
        }
        
        for (int i = cur; i < num.size(); i++)
        {
            string path = num.substr(cur, i - cur + 1);
            if (path.size() > 1 && path[0] == '0')
            {
                return;
            }
            paths.push_back(path);
            dfs(num, i + 1, paths, res);
            paths.pop_back();
        }
        
    }
    
    bool isValidPaths(const vector<string>& paths) const
    {
        for (int i = 2; i < paths.size(); i++)
        {
            const long num1 = stol(paths[i - 2]);
            const long num2 = stol(paths[i - 1]);
            const long num = stol(paths[i]);
            if (num1 + num2 != num)
            {
                return false;
            }
        }
        
        return true;
    }   
};
