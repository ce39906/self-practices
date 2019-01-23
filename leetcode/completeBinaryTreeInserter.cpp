/*************************************************************************
    > File Name: completeBinaryTreeInserter.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-08 15:31:49
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        tree_root = new TreeNode(root->val);
        cur = tree_root;
        index = 0;
        last_level.push_back(tree_root);
        // level order traverse from second level
        queue<TreeNode*> que;
        if (root->left)
        {
            que.push(root->left);
        }
        
        if (root->right)
        {
            que.push(root->right);
        }
        
        while (!que.empty())
        {
            TreeNode* front = que.front();
            que.pop();
            insert(front->val);
            if (front->left)
            {
                que.push(front->left);
            }
            if (front->right)
            {
                que.push(front->right);
            }
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        if (!cur->left)
        {
            cur->left = node;
            cur_level.push_back(node);
            return cur->val;
        }
        
        cur->right = node;
        cur_level.push_back(node);
        int tmp = cur->val;
        // we don't reach the level's end
        if (index != last_level.size() - 1)
        {
            index++;
            cur = last_level[index];
        }
        else 
        {
            last_level.swap(cur_level);
            cur_level.clear();
            index = 0;
            cur = last_level.front();
        }
        
        return tmp;
      
    }
    
    TreeNode* get_root() {
        return tree_root;
    }
private:
    TreeNode* tree_root;
    vector<TreeNode*> last_level;
    vector<TreeNode*> cur_level;
    TreeNode* cur;
    size_t index;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        root_ = root;
        levelOrderTraversal(root);
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        const int size = levels.back().size();
        const int l = levels.size();
        int res;
        // last level full
        if (1 << (l - 1) == size)
        {
            TreeNode* parent = levels.back().front();
            res = parent->val;
            parent->left = node;
            levels.push_back(vector<TreeNode*>{node});
        }
        else // not full
        {
            TreeNode* parent = levels[l - 2][size / 2];
            res = parent->val;
            if (size & 1)
            {
                parent->right = node;
            }
            else
            {
                parent->left = node;
            }
            levels.back().push_back(node);
        }
        
        return res;
    }
    
    TreeNode* get_root() {
        return root_;
    }

private:
    void levelOrderTraversal(TreeNode* root)
    {
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            const int size = que.size();
            vector<TreeNode*> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = que.front();
                que.pop();
                level.push_back(front);
                if (front->left)
                {
                    que.push(front->left);
                }
                
                if (front->right)
                {
                    que.push(front->right);
                }
            }
            levels.push_back(level);
        }
    }
    
    TreeNode* root_;
    vector<vector<TreeNode*>> levels;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
