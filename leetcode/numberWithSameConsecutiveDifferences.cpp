/*************************************************************************
    > File Name: numberWithSameConsecutiveDifferences.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-10 19:42:16
 ************************************************************************/
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1)
        {
            vector<int> res(10);
            iota(res.begin(), res.end(), 0);
            return res;
        }
        
        string path;
        vector<string> paths;
        
        unordered_set<int> allowed_fronts;
        for (int i = 0; i + K < 10; i++)
        {
            allowed_fronts.insert(i);
            allowed_fronts.insert(i + K);
        }
        allowed_fronts.erase(0);
        
        dfs(N, K, allowed_fronts, path, paths);
        vector<int> res;
        res.reserve(paths.size());
        for (const string& path : paths)
        {
            res.push_back(stoi(path));
        }
        
        return res;
    }
private:
    void dfs(const int N,
             const int K,
             const unordered_set<int>& allowed_fronts,
             string& path,
             vector<string>& paths) const
    {
        if (path.size() == N)
        {
            paths.push_back(path);
            return;
        }
        
        if (path.empty())
        {
            for (const int front : allowed_fronts)
            {
                path.push_back(front + '0');
                dfs(N, K, allowed_fronts, path, paths);
                path.pop_back();
            }
        }
        else
        {
            int last = path.back() - '0';
            char c;
            if (last - K >= 0)
            {
                c = last - K + '0';
                path.push_back(c);
                dfs(N, K, allowed_fronts, path, paths);
                path.pop_back();
            }
            
            if (last + K < 10 && K != 0)
            {
                c = last + K + '0';
                path.push_back(c);
                dfs(N, K, allowed_fronts, path, paths);
                path.pop_back();
            }
        }
    }
};
