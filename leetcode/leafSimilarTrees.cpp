/*************************************************************************
    > File Name: leafSimilarTrees.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-02 11:07:43
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;
        allLeafs(root1, leafs1);
        allLeafs(root2, leafs2);
        
        return leafs1 == leafs2;
    }
private:
    void allLeafs(TreeNode* root, vector<int>& leafs) const
    {
        if (!root)
        {
            return;
        }
        
        if (!root->left && !root->right)
        {
            leafs.push_back(root->val);
        }
        
        if (root->left)
        {
            allLeafs(root->left, leafs);    
        }
        
        if (root->right)
        {
            allLeafs(root->right, leafs);
        }
    }
};
