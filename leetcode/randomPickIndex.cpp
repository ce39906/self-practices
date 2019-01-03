/*************************************************************************
    > File Name: randomPickIndex.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-03 17:41:25
 ************************************************************************/
class Solution {
public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (num_2_idxs.count(nums[i]))
            {
                num_2_idxs[nums[i]].push_back(i);
            }
            else
            {
                num_2_idxs[nums[i]] = vector<int>(1, i);
            }
        }
    }
    
    int pick(int target) {
        const vector<int>& idxs = num_2_idxs.at(target);
        const int n = idxs.size();
        return idxs[rand() % n];
    }
private:
    unordered_map<int, vector<int>> num_2_idxs;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
