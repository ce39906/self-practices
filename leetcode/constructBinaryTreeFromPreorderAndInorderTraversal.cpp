/*************************************************************************
    > File Name: constructBinaryTreeFromPreorderAndInorderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-11 15:53:42
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_last = preorder.size() - 1;
        int in_last = inorder.size() - 1;
        TreeNode* root = buildTree(preorder, inorder, 0, pre_last, 0, in_last);
        return root;
    }
private:
    TreeNode* buildTree(const vector<int>& preorder,
                        const vector<int>& inorder,
                        int pre_first,
                        int pre_last,
                        int in_first,
                        int in_last) const
    {
        if (pre_first > pre_last)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[pre_first]);
        int pos;
        for (int i = in_first; i <= in_last; i++)
        {
            if (inorder[i] == preorder[pre_first])
            {
                pos = i;
                break;
            }
        }
        
        TreeNode* left_node = buildTree(preorder,
                                        inorder,
                                        pre_first + 1,
                                        pre_first + (pos - in_first),
                                        in_first,
                                        pos - 1);
        TreeNode* right_node = buildTree(preorder,
                                         inorder,
                                         pre_first + (pos - in_first) + 1,
                                         pre_last,
                                         pos + 1,
                                         in_last);
        root->left = left_node;
        root->right = right_node;
        return root;
    }
};
