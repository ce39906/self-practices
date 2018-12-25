/*************************************************************************
    > File Name: intersectionOfTwoArrays.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 17:08:23
 ************************************************************************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> unique_nums1(nums1.begin(), nums1.end());
        unordered_set<int> unique_nums2(nums2.begin(), nums2.end());
        
        vector<int> res;
        for (auto cit = unique_nums1.cbegin(); cit != unique_nums1.cend(); ++cit)
        {
            if (unique_nums2.count(*cit))
            {
                res.push_back(*cit);
            }
        }
        
        return res;
    }
};
