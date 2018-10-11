/*************************************************************************
    > File Name: constructBinaryTreeFromInorderAndPostorderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-11 16:26:08
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_last = inorder.size() - 1;
        int post_last = postorder.size() - 1;
        TreeNode* root = buildTree(inorder, postorder, 0, in_last, 0, post_last);
        
        return root;
    }
private:
    TreeNode* buildTree(const vector<int>& inorder,
                        const vector<int>& postorder,
                        int in_first,
                        int in_last,
                        int post_first,
                        int post_last) const
    {
        if (post_first > post_last || in_first > in_last)
        {
            return NULL;
        }
        
        int pos;
        for (int i = in_first; i <= in_last; i++)
        {
            if (inorder[i] == postorder[post_last])
            {
                pos = i;
                break;
            }
        }
        
        TreeNode* left_node = buildTree(inorder,
                                        postorder,
                                        in_first,
                                        pos - 1,
                                        post_first,
                                        post_first + (pos - in_first) - 1);
        TreeNode* right_node = buildTree(inorder,
                                         postorder,
                                         pos + 1,
                                         in_last,
                                         post_first + pos - in_first,
                                         post_last - 1);
        TreeNode* root = new TreeNode(postorder[post_last]);
        root->left = left_node;
        root->right = right_node;
        
        return root;
    }
};
