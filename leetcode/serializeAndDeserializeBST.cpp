/*************************************************************************
    > File Name: serializeAndDeserializeBST.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-17 16:03:39
 ************************************************************************/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized = "";
        if (!root) 
        {
            return nil;
        }
        // pre order traversal
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* top = s.top();
            s.pop();
            serialized.append(to_string(top->val));
            serialized.append(1, sep);
            if (top->right)
            {
                s.push(top->right);
            }

            if (top->left)
            {
                s.push(top->left);
            }
        }

        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == nil)
        {
            return nullptr;
        }
        queue<int> vals;
        stringstream ss(data);
        string val;
        while (getline(ss, val, sep))
        {
            vals.push(stoi(val));
        }

        return helper(vals);
    }
private:
    TreeNode* helper(queue<int>& vals)
    {
        if (vals.empty())
        {
            return nullptr;
        }

        const int front = vals.front();
        vals.pop();
        TreeNode* root = new TreeNode(front);
        queue<int> left_part;
        while (!vals.empty() && vals.front() < front)
        {
            left_part.push(vals.front());
            vals.pop();
        }
        
        root->left = helper(left_part);
        root->right = helper(vals);
        
        return root;
    }

    inline static const char sep = ',';
    inline static const std::string nil = "null";
};
