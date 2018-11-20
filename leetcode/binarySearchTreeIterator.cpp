/*************************************************************************
    > File Name: binarySearchTreeIterator.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-20 19:32:49
 ************************************************************************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root)
        {
            traverse(root);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !que.empty();
    }

    /** @return the next smallest number */
    int next() {
        int val = que.front()->val;
        que.pop();
        return val;
    }
private:
    queue<TreeNode*> que;
    void traverse(TreeNode* node)
    {
        if (node->left)
        {
            traverse(node->left);
        }
        que.push(node);
        if (node->right)
        {
            traverse(node->right);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
