/*************************************************************************
    > File Name: NAryTreeLevelOrderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-08 13:55:45
 ************************************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<Node*> que;
        que.push(root);
        while(!que.empty())
        {
            const size_t size = que.size();
            vector<int> line(size);
            for (size_t i = 0; i < size; i++)
            {
                const Node* front = que.front();
                line[i] = front->val;
                que.pop();
                for (const auto& child : front->children)
                {
                    if (!child)
                    {
                        continue;
                    }
                    que.push(child);
                }
            }
            res.emplace_back(std::move(line));
        }
        return res;
    }
};
