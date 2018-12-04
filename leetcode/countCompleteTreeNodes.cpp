/*************************************************************************
    > File Name: countCompleteTreeNodes.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-04 19:41:22
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
    int countNodes(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        
        int hl = 0;
        int hr = 0;
        TreeNode* l = root;
        TreeNode* r = root;
        while (l)
        {
            hl++;
            l = l->left;
        }
        while (r)
        {
            hr++;
            r = r->right;
        }
        
        if (hl == hr)
        {
            return pow(2, hl) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
