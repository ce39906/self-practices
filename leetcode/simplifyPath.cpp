/*************************************************************************
    > File Name: simplifyPath.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-30 19:45:04
 ************************************************************************/
class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
        {
            return "";
        }
        // first split path by '/'
        stringstream ss(path);
        vector<string> dirs;
        string dir;
        while (std::getline(ss, dir, '/'))
        {
            if (!dir.empty() && dir != ".")
            {
                dirs.push_back(dir);
            }
        }
        
        stack<string> s;
        for (const auto& dir : dirs)
        {
            if (dir == "..")
            {
                if (!s.empty())
                {
                    s.pop();
                }
            }
            else
            {
                s.emplace(dir);
            }
        }
        
        string res = "";
        while (!s.empty())
        {
            res = s.top() + "/" + res;
            s.pop();
        }
        
        res = "/" + res;
        
        if (res.size() > 1 && res.back() == '/')
        {
            res.resize(res.size() - 1);   
        }
        
        return res;
    }
};
