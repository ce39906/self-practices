/*************************************************************************
    > File Name: checkCompletenessOfABinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-11 15:33:14
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
    bool isCompleteTree(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        
        bool last_level_suffix_null = false;
        while(!que.empty())
        {
            int size = que.size();
            bool prefix_null = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = que.front();
                que.pop();
                if (!front)
                {
                    prefix_null = true;
                }
                else
                {
                    if (prefix_null || last_level_suffix_null)
                    {
                        return false;
                    }
                    
                    que.push(front->left);
                    que.push(front->right);
                }
                
                if (i == size - 1 && !front)
                {
                    last_level_suffix_null = true;
                }
            }
            
        }
        
        return true;
    }
};
