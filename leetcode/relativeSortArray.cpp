/*************************************************************************
    > File Name: relativeSortArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 15:05:12
 ************************************************************************/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> num_2_idx;
        for (int i = 0; i < arr2.size(); i++)
        {
            num_2_idx[arr2[i]] = i;
        }
        vector<int> buckets(arr2.size(), 0);
        vector<int> left;
        for (const int num : arr1)
        {
            if (num_2_idx.count(num))
            {
                buckets[num_2_idx[num]]++;
            }
            else
            {
                left.push_back(num);
            }        
        }
        sort(left.begin(), left.end());
        vector<int> res;
        for (int i = 0; i < buckets.size(); i++)
        {
            int cnt = buckets[i];
            while (cnt--)
            {
                res.push_back(arr2[i]);
            }
        }
        copy(left.begin(), left.end(), back_inserter(res));
        return res;
    }
};
