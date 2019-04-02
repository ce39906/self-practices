/*************************************************************************
    > File Name: cloneGraph.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-27 11:01:53
 ************************************************************************/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
        {
            return nullptr;
        }
        Node* copy = new Node(node->val, {});
        copies[node] = copy;
        queue<Node*> que;
        que.push(node);
        while (!que.empty())
        {
            Node* front = que.front();
            que.pop();
            for (Node* neighbor : front->neighbors)
            {
                if (!copies.count(neighbor))
                {
                    copies[neighbor] = new Node(neighbor->val, {});
                    que.push(neighbor);
                }
                copies[front]->neighbors.push_back(copies[neighbor]);
            }
        }

        return copy;
    }
private:
    unordered_map<Node*, Node*> copies;
};
