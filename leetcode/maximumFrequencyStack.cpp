/*************************************************************************
    > File Name: maximumFrequencyStack.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-28 14:21:39
 ************************************************************************/
class FreqStack {
public:
    FreqStack() {
        max_freq_ = 0;
    }
    
    void push(int x) {
        max_freq_ = max(max_freq_, ++num_2_freqs[x]);
        freq_2_nums[num_2_freqs[x]].push(x);
    }
    
    int pop() {
        int top = freq_2_nums[max_freq_].top();
        freq_2_nums[max_freq_].pop();
        num_2_freqs[top]--;
        if (freq_2_nums[max_freq_].empty())
        {
            max_freq_--;
        }
        
        return top;
    }
private:
    int max_freq_;
    unordered_map<int, stack<int>> freq_2_nums;
    unordered_map<int, int> num_2_freqs;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
