/*************************************************************************
    > File Name: uniqueEmailAddresses.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-21 16:16:47
 ************************************************************************/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (const string& email : emails)
        {
            s.insert(amendEmail(email));
        }
        
        return s.size();
    }
private:
    string amendEmail(const string& email) const
    {
        size_t at_idx = email.find('@');
        string local_name = email.substr(0, at_idx);
        size_t plus_idx = local_name.find('+');
        if (plus_idx != string::npos)
        {
            local_name = local_name.substr(0, plus_idx);
        }
        
        for (auto it = local_name.begin(); it != local_name.end();)
        {
            if (*it == '.')
            {
                local_name.erase(it);
            }
            else
            {
                ++it;
            }
        }
        
        return local_name + email.substr(at_idx);
    }   
};
