/*************************************************************************
    > File Name: slidingWindowMaximum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-06 19:18:06
 ************************************************************************/
class MonotoneQueue {
public:
    void push(int x)
    {
        que.push_back(x);
        while (!max_que.empty() && max_que.back() < x)
        {
            max_que.pop_back();
        }
        max_que.push_back(x);
    }
    
    void pop()
    {
        int front = que.front();
        que.pop_front();
        if (front == max_que.front())
        {
            max_que.pop_front();
        }
    }
    
    int max()
    {
        return max_que.front();
    }
    
private:
    deque<int> que;
    deque<int> max_que;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        const int size = nums.size();
        if (size == 0 || k == 0)
        {
            return res;
        }
        
        MonotoneQueue monotone_que;
        for (int i = 0; i < k; i++)
        {
            monotone_que.push(nums[i]);
        }
        
        res.push_back(monotone_que.max());
        
        for (int i = k; i < size; i++)
        {
            monotone_que.pop();
            monotone_que.push(nums[i]);
            res.push_back(monotone_que.max());
        }
        
        return res;
    }
};
