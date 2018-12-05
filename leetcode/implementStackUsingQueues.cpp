/*************************************************************************
    > File Name: implementStackUsingQueues.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-05 16:45:49
 ************************************************************************/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size = que.size();
        que.push(x);
        for (int i = 0; i < size; i++)
        {
            const int front = que.front();
            que.pop();
            que.push(front);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front = que.front();
        que.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
