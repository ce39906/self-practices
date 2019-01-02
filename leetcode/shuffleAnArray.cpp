/*************************************************************************
    > File Name: shuffleAnArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-02 16:38:52
 ************************************************************************/
class Solution {
public:
    Solution(vector<int> nums) {
        nums_ = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = nums_;
        const int size = nums_.size();
        for (int i = 0; i < size; i++)
        {
            int idx = rand() % size;
            if (i == idx)
            {
                continue;
            }
            swap(shuffled[i], shuffled[idx]);
        }
        
        return shuffled;
    }
private:
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
