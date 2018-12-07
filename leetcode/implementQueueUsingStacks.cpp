/*************************************************************************
    > File Name: implementQueueUsingStacks.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-06 11:07:08
 ************************************************************************/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        vector<int> tmp;
        while (!s.empty())
        {
            tmp.push_back(s.top());
            s.pop();
        }
        int val = tmp.back();
        tmp.pop_back();
        for (auto rit = tmp.rbegin(); rit != tmp.rend(); ++rit)
        {
            s.push(*rit);
        }
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        vector<int> tmp;
        while (!s.empty())
        {
            tmp.push_back(s.top());
            s.pop();
        }
        int val = tmp.back();
        for (auto rit = tmp.rbegin(); rit != tmp.rend(); ++rit)
        {
            s.push(*rit);
        }
        return val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
private:
    stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
