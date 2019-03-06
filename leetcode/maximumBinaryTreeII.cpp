/*************************************************************************
    > File Name: maximumBinaryTreeII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-05 11:47:19
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> list = maxTreeToList(root);
        list.push_back(val);
        return listToMaxTree(list, 0, list.size() - 1);
    }
    
private:
    vector<int> maxTreeToList(TreeNode* root) const
    {
        if (!root)
        {
            return {};
        }
        
        vector<int> left = maxTreeToList(root->left);
        vector<int> right = maxTreeToList(root->right);
        left.push_back(root->val);
        copy(right.begin(), right.end(), back_inserter(left));
        
        return left;
    }
    
    TreeNode* listToMaxTree(const vector<int>& vals,
                            int first,
                            int last) const
    {
        if (first > last)
        {
            return nullptr;
        }
        
        if (first == last)
        {
            return new TreeNode(vals[first]);    
        }
        
        auto it = max_element(vals.begin() + first, vals.begin() + last + 1);
        int max_idx = it - vals.begin();
        
        TreeNode* root = new TreeNode(*it);
        TreeNode* left = listToMaxTree(vals, first, max_idx - 1);
        TreeNode* right = listToMaxTree(vals, max_idx + 1, last);
        root->left = left;
        root->right = right;
        
        return root;
    }
};
