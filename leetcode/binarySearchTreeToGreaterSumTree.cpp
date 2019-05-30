/*************************************************************************
    > File Name: binarySearchTreeToGreaterSumTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-05-30 11:42:10
 ************************************************************************/
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> nodes = traversal(root);
        for (int i = 1; i < nodes.size(); i++)
        {
            nodes[i]->val += nodes[i - 1]->val;
        }

        return root;
    }
private:
    vector<TreeNode*> traversal(TreeNode* root)
    {
        if (!root)
        {
            return {};
        }
        vector<TreeNode*> left = traversal(root->left);
        vector<TreeNode*> right = traversal(root->right);
        right.push_back(root);
        copy(left.begin(), left.end(), std::back_inserter(right));

        return right;
    }
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> nodes = traversal(root);
        for (int i = 1; i < nodes.size(); i++)
        {
            nodes[i]->val += nodes[i - 1]->val;
        }

        return root;
    }
private:
    vector<TreeNode*> traversal(TreeNode* root)
    {
        if (!root)
        {
            return {};
        }
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<TreeNode*> res;
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->right;
            }

            if (!s.empty())
            {
                TreeNode* top = s.top();
                s.pop();
                res.push_back(top);
                cur = top->left;
            }
        }

        return res;
    }
};
