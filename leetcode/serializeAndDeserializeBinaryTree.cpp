/*************************************************************************
    > File Name: serializeAndDeserializeBinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-05-22 15:42:28
 ************************************************************************/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out)
    {
        if (root == nullptr)
        {
            out << "# ";
        }
        else
        {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
    }

    TreeNode* deserialize(istringstream& in)
    {
        string val;
        in >> val;
        if (val == "#")
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        
        return root;
    }
};
