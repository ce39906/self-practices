/*************************************************************************
    > File Name: minStack.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 15:01:01
 ************************************************************************/
struct Node
{
    Node (int val, int min) : val(val), min(min)
    {
        
    }
    int val;
    int min;
};

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        Node node(x, x);
        if (s.empty())
        {
            s.push(node);
            return;
        }
        
        int cur_min = s.top().min;
        cur_min = min(x, cur_min);
        s.push(Node(x, cur_min));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().val;
    }
    
    int getMin() {
        return s.top().min;
    }
    
private:
    stack<Node> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
