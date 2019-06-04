/*************************************************************************
    > File Name: constructBinarySearchTreeFromPreorderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-04 17:40:35
 ************************************************************************/
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int end = preorder.size() - 1;
        return bstFromPreorder(preorder, 0, end);
    }
private:
    TreeNode* bstFromPreorder(const vector<int>& preorder,
                              int start,
                              int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        if (start == end)
        {
            return new TreeNode(preorder[start]);
        }

        const int val = preorder[start];
        TreeNode* root = new TreeNode(val);
        if (preorder[start + 1] > val)
        {
            root->left = nullptr;
            root->right = bstFromPreorder(preorder, start + 1, end);
        }
        else
        {
            int left_start = start + 1;
            while (left_start <= end && preorder[left_start] < val)
            {
                left_start++;
            }
            left_start--;
            root->left = bstFromPreorder(preorder, start + 1, left_start);
            root->right = bstFromPreorder(preorder, left_start + 1, end);
        }
        
        return root;
    }
};
