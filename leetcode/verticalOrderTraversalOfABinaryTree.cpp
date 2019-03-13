/*************************************************************************
    > File Name: verticalOrderTraversalOfABinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-13 17:30:30
 ************************************************************************/
struct Node
{
    Node(int x, int y, int val) : x(x), y(y), val(val)
    {
    }

    int x;
    int y;
    int val;
    bool operator<(const Node& rhs) const
    {
        if (x < rhs.x)
        {
            return true;
        }
        else if (x == rhs.x)
        {
            if (y > rhs.y)
            {
                return true;
            }
            else if (y == rhs.y)
            {
                return val < rhs.val;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<Node> nodes;
        dfs(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> res;
        int cur_x = nodes.front().x;
        vector<int> cur;
        cur.push_back(nodes.front().val);
        for (int i = 1; i < nodes.size(); i++)
        {
            const Node& node = nodes.at(i);
            if (node.x == cur_x)
            {
                cur.push_back(node.val);
            }
            else
            {
                cur_x = node.x;
                res.push_back(cur);
                cur = vector<int>(1, node.val);
            }
        }

        if (!cur.empty())
        {
            res.push_back(cur);
        }

        return res;
    }
private:
    void dfs(TreeNode* root,
             int x,
             int y,
             vector<Node>& nodes)
    {
        if (!root)
        {
            return;
        }
        nodes.emplace_back(x, y, root->val);
        if (root->left)
        {
            dfs(root->left, x - 1, y - 1, nodes);
        }

        if (root->right)
        {
            dfs(root->right, x + 1, y - 1, nodes);
        }
    }
};
