/*************************************************************************
    > File Name: compareVersionNumbers.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 19:31:34
 ************************************************************************/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        const auto split_version = [](const string& version)
        {
            string word;
            stringstream ss(version);
            vector<int> versions;
            while (getline(ss, word, '.'))
            {
                versions.push_back(stoi(word));
            }
            return versions;
        };
        
        vector<int> versions1 = split_version(version1);
        vector<int> versions2 = split_version(version2);
    
        // trim right zeros
        const auto trim_right_zero = [](vector<int>& versions){
            for (auto rit = versions.rbegin(); rit != versions.rend(); ++rit)
            {
                if (*rit)
                {
                    return;
                }
                
                if (versions.size() > 1)
                {
                    versions.pop_back();
                }
            }
        };
        
        trim_right_zero(versions1);
        trim_right_zero(versions2);
        // compare
        const int size1 = versions1.size();
        const int size2 = versions2.size();
        const int size = min(size1, size2); 
        for (int i = 0; i < size; i++)
        {
            if (versions1[i] > versions2[i])
            {
                return 1;
            }
            else if (versions1[i] < versions2[i])
            {
                return -1;
            }
            else
            {
                continue;
            }
        }
        
        if (size1 > size2)
        {
            return 1;
        }
        
        if (size1 < size2)
        {
            return -1;
        }
        
        return 0;
    }
};
