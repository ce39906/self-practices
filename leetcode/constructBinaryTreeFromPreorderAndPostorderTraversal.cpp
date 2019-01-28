/*************************************************************************
    > File Name: constructBinaryTreeFromPreorderAndPostorderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-28 15:20:39
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty() || post.empty())
        {
            return NULL;
        }
        // post is ordered by root, right, left
        reverse(post.begin(), post.end());
        TreeNode* root = buildTree(pre,
                                   post,
                                   0,
                                   pre.size() - 1,
                                   0,
                                   post.size() - 1);
        
        return root;
    }
private:
    TreeNode* buildTree(const vector<int>& pre,
                        const vector<int>& fake_post,
                        int pre_i,
                        int pre_j,
                        int fake_post_i,
                        int fake_post_j) const
    {
        if (pre_i > pre_j)
        {
            return NULL;
        }
        
        if (pre_i == pre_j)
        {
            return new TreeNode(pre[pre_i]);
        }
        
        const int root_val = pre[pre_i];
        TreeNode* root = new TreeNode(root_val);
        const int left_val = pre[pre_i + 1];
        
        if (pre_i + 1 == pre_j)
        {
            root->left = new TreeNode(left_val);
            return root;
        }
        
        // find right_tree;
        int i = fake_post_i;
        for (; i <= fake_post_j; i++)
        {
            if (fake_post[i] == left_val)
            {
                break;
            }
        }
        
        int left_len = fake_post_j - i + 1;
        // left tree is NULL
        if (i == fake_post_i)
        {
            left_len = 0;
        }
        
        TreeNode* left = buildTree(pre,
                                   fake_post,
                                   pre_i + 1,
                                   pre_i + left_len,
                                   i,
                                   fake_post_j);
        
        TreeNode* right = buildTree(pre,
                                    fake_post,
                                    pre_i + left_len  + 1,
                                    pre_j,
                                    fake_post_i + 1,
                                    i - 1);
        root->left = left;
        root->right = right;
        
        return root;
    }
};
