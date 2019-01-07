/*************************************************************************
    > File Name: queueReconstructionByHeight.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-04 11:02:14
 ************************************************************************/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),compartor());
        vector<pair<int,int>> res;
        res.reserve(people.size());
        for(const auto& person : people)
        {
            res.insert(res.begin() + person.second, person);
        }
        return res;
    }
    struct compartor
    {
        bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs) const
        {
            if(lhs.first > rhs.first)
            {
                return true;
            }
            else if (lhs.first == rhs.first)
            {
                if (lhs.second <= rhs.second)
                {
                    return true;
                }
            }
            return false;
        }
    };
};
